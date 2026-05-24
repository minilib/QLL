// SPDX-License-Identifier: MIT OR Apache-2.0
export module FLL.Core.Base.Timer;
import FLL.Core.Base.Types;
import std;
using namespace std;
using namespace chrono;
inline steady_clock::time_point sNow() {return steady_clock::now(); }
namespace FLL {
    using Sec = seconds;
    using MS = milliseconds;
    using US = microseconds;
    using NS = nanoseconds;
};
export namespace FLL {
    class Time {
        public:
            Time() noexcept : time_(0) {}
            Time(nanoseconds time) noexcept : time_(time) {}
            float asSecF() noexcept {return duration_cast<duration<float>>(time_).count(); }
            double asSecD() noexcept {return duration_cast<duration<double>>(time_).count(); }
            long long asSecI() noexcept {return duration_cast<Sec>(time_).count(); }
            Sec asSecC() noexcept {return duration_cast<Sec>(time_); }
            float asMsF() noexcept {return duration_cast<duration<float, milli>>(time_).count(); }
            double asMsD() noexcept {return duration_cast<duration<double, milli>>(time_).count(); }
            long long asMsI() noexcept {return duration_cast<MS>(time_).count(); }
            MS asMsC() noexcept {return duration_cast<MS>(time_); }
            float asUsF() noexcept {return duration_cast<duration<float, micro>>(time_).count(); }
            double asUsD() noexcept {return duration_cast<duration<double, micro>>(time_).count(); }
            long long asUsI() noexcept {return duration_cast<US>(time_).count(); }
            US asUsC() noexcept {return duration_cast<US>(time_); }
            float asNsF() noexcept {return duration_cast<duration<float, nano>>(time_).count(); }
            double asNsD() noexcept {return duration_cast<duration<double, nano>>(time_).count(); }
            long long asNsI() noexcept {return duration_cast<NS>(time_).count(); }
            NS asNsC() noexcept {return duration_cast<NS>(time_); }
        private:
            nanoseconds time_;
    };
    class Timer {
    public:
        Timer() noexcept : startTime_(sNow()), lastFrameTime_(sNow()) {}
        void Reset() noexcept {startTime_ = lastFrameTime_ = sNow(); }
        Time get() noexcept {
            Time obj(sNow() - startTime_);
            return obj;
        }
        Time getDeltaTime() noexcept {
            Time obj(sNow() - lastFrameTime_);
            return obj;
        }
    private:
        steady_clock::time_point startTime_; 
        steady_clock::time_point lastFrameTime_;
    };
}