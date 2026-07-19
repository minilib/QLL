// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
// //Copyright (c) 2026 minilib

export module QLL.Core.Infra.Log;
import std;
import QLL.Core.Base.Types;
#ifndef LOG_LEVEL
    #ifdef NDEBUG
        constexpr int LOG_LEVEL = 3;
    #else
        constexpr int LOG_LEVEL = 0;
    #endif
#endif
std::mutex logMutex;
namespace QLL {
export enum class LogLevel : u1 {
    Debug,
    Info,
    Warning,
    Error
};
/**
 * @brief put log to stdout
 * @details use @c std::mutex , so threadsafe.
 * @note Since write operations are performed synchronously, performance may degrade if called from many threads.
 */
class LoggerImpl {
    public:
        static LoggerImpl& getInstance() {
            static LoggerImpl instance;
            return instance;
        }
        /**
         *@brief Function to output formatted log to standard output
         *
         *@tparam Args Specify what to output to the log
         *@param[in] level Specify log level
         *@param[in] format Format string input in printf format
         *@param[in] args to enter in args format
         */
        template<typename T, typename... Args>
        void Log(LogLevel level, const char* format, Args... args) {if(static_cast<int>(level) >= LOG_LEVEL) iLog(level, std::forward<T>(format), args...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Debug when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in printf format
         * @param[in] args to enter in args format
         */
        template<typename T, typename... Args>
        void Debug(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Debug) >= LOG_LEVEL) iLog(LogLevel::Debug, std::forward<T>(format), args...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Info when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in printf format
         * @param[in] args to enter in args format
         */
        template<typename T, typename... Args>
        void Info(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Info) >= LOG_LEVEL) iLog(LogLevel::Info, std::forward<T>(format), args...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Warn when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in printf format
         * @param[in] args to enter in args format
         */
        template<typename T, typename... Args>
        void Warn(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Warning) >= LOG_LEVEL) iLog(LogLevel::Warning, std::forward<T>(format), args...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Error when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in printf format
         * @param[in] args to enter in args format
         */
        template<typename T, typename... Args>
        void Error(const char* format, Args... args) noexcept {if constexpr (static_cast<int>(LogLevel::Error) >= LOG_LEVEL) iLog(LogLevel::Error, std::forward<T>(format), args...); }
    private:
        bool timestamp_ = true;
        LoggerImpl() {}
        template<typename... Args>
        void iLog(LogLevel level, const char* format, Args... args) {
            std::lock_guard<std::mutex> lock(logMutex);
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
            std::print(format, label, std::forward<Args>(args)...);
        };
};
inline LoggerImpl& Logger = LoggerImpl::getInstance();
}