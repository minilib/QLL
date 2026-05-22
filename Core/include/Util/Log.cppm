// SPDX-License-Identifier: MIT OR Apache-2.0
export module FLL.Core.Core:Log;
import std;
import FLL.Core.Base.Types;
#ifndef LOG_LEVEL
    #ifdef NDEBUG
        #define LOG_LEVEL 3
    #else
        #define LOG_LEVEL 1
    #endif
#endif
export namespace FLL {
    // ログの重要度
    enum class LogLevel : u1 {
        Debug,
        Info,
        Warning,
        Error
    };
}
using L = FLL::LogLevel;
export namespace FLL {
class Logger {
    public:
        template<typename... Args>
        static void Log(LogLevel level, const char* format, Args... args) {
            static std::mutex mtx;
            std::lock_guard<std::mutex> lock(mtx);
            char buffer[1024];
            const char* label = "";
            switch(level) {
                case L::Debug:
                    label = "[DEBUG]";
                    break;
                case L::Info:
                    label = "[INFO] ";
                    break;
                case L::Warning:
                    label = "[WARN] ";
                    break;
                case L::Error:
                    label = "[ERROR]";
                    break;
            }
            constexpr size_t labelLen = 7;
            if (offset_ + labelLen < sizeof(huge_buffer_) - 1) {
                std::memcpy(&huge_buffer_[offset_], label, labelLen);
                offset_ += labelLen;
            }
            
            template for (auto val : args) {
                if constexpr (std::is_arithmetic_v<decltype(val)>) {
                    auto [ptr, ec] = std::to_chars(buffer, buffer + sizeof(buffer), val);
                    size_t len = static_cast<size_t>(ptr - buffer);
                    if (offset_ + len < sizeof(huge_buffer_) - 1) {
                        std::memcpy(&huge_buffer_[offset_], buffer, len);
                        offset_ += len;
                    } else {
                        printf("%s", &huge_buffer_);
                        offset_ = 0;
                        std::memcpy(&huge_buffer_[offset_], val.data(), len);
                        offset_ += len;
                    }
                } else {
                    std::string_view sv = val;
                    size_t len = sv.size();
                    if (offset_ + len < sizeof(huge_buffer_) - 1) {
                        std::memcpy(huge_buffer_ + offset_, sv.data(), len);
                        offset_ += len;
                    } else {
                        printf("%s", huge_buffer_);
                        offset_ = 0;
                        std::memcpy(huge_buffer_, sv.data(), len);
                        offset_ += len;
                    }
                }
            }
        };
        template<typename... Args>
        static void Debug(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(L::Debug) >= LOG_LEVEL) Log(L::Debug, format, args...); }
        template<typename... Args>
        static void Info(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(L::Info) >= LOG_LEVEL) Log(L::Info, format, args...); }
        template<typename... Args>
        static void Warn(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(L::Warning) >= LOG_LEVEL) Log(L::Warning, format, args...); }
        template<typename... Args>
        static void Error(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(L::Error) >= LOG_LEVEL) Log(L::Error, format, args...); }
    private:
        static char huge_buffer_[64 * 1024];
        static inline size_t offset_ = 0;
        Logger() {}
        
    };

}