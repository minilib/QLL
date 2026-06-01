// SPDX-License-Identifier: MIT OR Apache-2.0

export module QLL.Core.Core:Log;
import std;
import QLL.Core.Base.Types;
#ifndef LOG_LEVEL
    #ifdef NDEBUG
        #define LOG_LEVEL 3
    #else
        #define LOG_LEVEL 1
    #endif
#endif
export namespace FLL {
enum class LogLevel : u1 {
    Debug,
    Info,
    Warning,
    Error
};
class Logger {
    public:
        /**
         *@brief Function to output formatted log to standard output
         *
         *@tparam Args Specify what to output to the log
         *@param[in] level Specify log level
         *@param[in] format Format string input in printf format
         *@param[in] Value to enter in args format
         */
        template<typename... Args>
        static void Log(LogLevel level, const char* format, Args... args) {if(static_cast<int>(level) >= LOG_LEVEL) iLog(level, format, args...); }
        template<typename... Args>
        static void Debug(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Debug) >= LOG_LEVEL) iLog(LogLevel::Debug, format, args...); }
        template<typename... Args>
        static void Info(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Info) >= LOG_LEVEL) iLog(LogLevel::Info, format, args...); }
        template<typename... Args>
        static void Warn(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Warning) >= LOG_LEVEL) iLog(LogLevel::Warning, format, args...); }
        template<typename... Args>
        static void Error(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Error) >= LOG_LEVEL) iLog(LogLevel::Error, format, args...); }
    private:
        static char huge_buffer_[64 * 1024];
        static inline i8 offset_ = 0;
        static inline bool timestamp_ = true;
        Logger() {}
        template<typename... Args>
        static void pLog(LogLevel level, const char* format, Args... args) {
            static std::mutex mtx;
            std::lock_guard<std::mutex> lock(mtx);
            char buffer[1024];
            const char* label = "";
            switch(level) {
                case LogLevel::Debug:
                    label = "[DEBUG]";
                    break;
                case LogLevel::Info:
                    label = "[INFO] ";
                    break;
                case LogLevel::Warning:
                    label = "[WARN] ";
                    break;
                case LogLevel::Error:
                    label = "[ERROR]";
                    break;
            }
            constexpr i8 labelLen = 7;
            if (offset_ + labelLen < sizeof(huge_buffer_) - 1) {
                std::memcpy(&huge_buffer_[offset_], label, labelLen);
                offset_ += labelLen;
            }
            (..., [&](auto val) {
                if constexpr (std::is_arithmetic_v<decltype(val)>) {
                    auto [ptr, ec] = std::to_chars(buffer, buffer + sizeof(buffer), val);
                    i8 len = static_cast<i8>(ptr - buffer);
                    if (offset_ + len < sizeof(huge_buffer_) - 1) {
                        std::memcpy(&huge_buffer_[offset_], buffer, len);
                        offset_ += len;
                    } else {
                        std::printf("%s", huge_buffer_);
                        offset_ = 0;
                        std::memcpy(&huge_buffer_[offset_], buffer, len);
                        offset_ += len;
                    }
                } else {
                    std::string_view sv = val;
                    i8 len = sv.size();
                    if (offset_ + len < sizeof(huge_buffer_) - 1) {
                        std::memcpy(huge_buffer_ + offset_, sv.data(), len);
                        offset_ += len;
                    } else {
                        std::printf("%s", huge_buffer_);
                        offset_ = 0;
                        std::memcpy(huge_buffer_, sv.data(), len);
                        offset_ += len;
                    }
                }
            }(args));
        };
};
}