// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
// //Copyright (c) 2026 minilib
module;
export module QLL.Core.Infra.Log;
import std;
import QLL.Core.Base.Types;
export namespace QLL {
enum class LogLevel : u1 {
    Debug,
    Info,
    Warning,
    Error,
    Fatal
};
}
#ifdef NDEBUG 
    constexpr bool timeStamp = false;
    #ifdef LOG_LEVEL
        constexpr QLL::LogLevel logLevel = static_cast<Loglevel>(LOG_LEVEL);
    #else 
        constexpr QLL::LogLevel logLevel = QLL::LogLevel::Error;
    #endif
#else 
    bool timeStamp = true;
    #ifdef LOG_LEVEL
        QLL::LogLevel logLevel = static_cast<Loglevel>(LOG_LEVEL);
    #else 
        QLL::LogLevel logLevel = QLL::LogLevel::Debug;
    #endif
#endif
std::mutex logMutex;
export namespace QLL {
/**
 * @brief put log to stdout
 * @details use @c std::mutex , so threadsafe.
 * @note Since write operations are performed synchronously, performance may degrade if called from many threads.
 */
class Logger {
    public:
        static Logger& getInstance() {
            static Logger instance;
            return instance;
        }
        /**
         *@brief Function to output formatted log to standard output
         *
         *@tparam Args Specify what to output to the log
         *@param[in] level Specify log level
         *@param[in] format Format string input in std::print format
         *@param[in] args to enter in args format
         */
        template<typename... Args>
        void log(LogLevel level, const char* format, Args... args) {{if (level >= ::logLevel) iLog(level, format, std::forward<Args>(args)...);} }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Debug when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in std::print format
         * @param[in] args to enter in args format
         */
        template<typename... Args>
        void debug(const char* format, Args... args) noexcept {if (LogLevel::Debug >= ::logLevel) iLog(LogLevel::Debug, format, std::forward<Args>(args)...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Info when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in std::print format
         * @param[in] args to enter in args format
         */
        template<typename... Args>
        void info(const char* format, Args... args) noexcept {if (LogLevel::Info >= ::logLevel) iLog(LogLevel::Info, format, std::forward<Args>(args)...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Warn when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in std::print format
         * @param[in] args to enter in args format
         */
        template<typename... Args>
        void warn(const char* format, Args... args) noexcept {if (LogLevel::Warning >= ::logLevel) iLog(LogLevel::Warning, format, std::forward<Args>(args)...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Error when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in std::print format
         * @param[in] args to enter in args format
         */
        template<typename... Args>
        void error(const char* format, Args... args) noexcept {if (LogLevel::Error >= ::logLevel) iLog(LogLevel::Error, format, std::forward<Args>(args)...); }
        /**
         * @copybrief Log()
         * @details Internally, the log level is fixed to @c Fatal when it is called.
         * @tparam Args Specify what to output to the log
         * @param[in] format Format string input in std::print format
         * @param[in] args to enter in args format
         */
        template<typename... Args>
        void fatal(const char* format, Args... args) noexcept {iLog(LogLevel::Error, format, std::forward<Args>(args)...); }
        LogLevel constexpr logLevel() noexcept {return ::logLevel; }
        void constexpr logLevel(LogLevel level) noexcept {::logLevel = level; }
        bool constexpr timeStamp() noexcept {return ::timeStamp; }
        void constexpr timeStamp(bool flag) noexcept {::timeStamp = flag; }
    private:
        Logger() {}
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
                case LogLevel::Fatal:
                    label = "[FATAL]";
                    break;
            }
            if (::timeStamp) {
                auto now = std::chrono::system_clock::now();
                std::print("{} {} ", now, label);
                std::println(format, std::forward<Args>(args)...);
            } else {
                std::print("{}", label);
                std::println(format, std::forward<Args>(args)...);
            }
        };
};
inline Logger& Log = Logger::getInstance();
}