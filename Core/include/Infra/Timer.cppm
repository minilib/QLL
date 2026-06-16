// SPDX-License-Identifier: MIT OR Apache-2.0
export module QLL.Core.Base.Timer;
import QLL.Core.Base.Types;
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
        f4 asSecF() noexcept {return duration_cast<duration<f4>>(time_).count(); }
        f8 asSecD() noexcept {return duration_cast<duration<f8>>(time_).count(); }
        i8 asSecI() noexcept {return duration_cast<Sec>(time_).count(); }
        Sec asSecC() noexcept {return duration_cast<Sec>(time_); }
        f4 asMsF() noexcept {return duration_cast<duration<f4, milli>>(time_).count(); }
        f8 asMsD() noexcept {return duration_cast<duration<f8, milli>>(time_).count(); }
        i8 asMsI() noexcept {return duration_cast<MS>(time_).count(); }
        MS asMsC() noexcept {return duration_cast<MS>(time_); }
        f4 asUsF() noexcept {return duration_cast<duration<f4, micro>>(time_).count(); }
        f8 asUsD() noexcept {return duration_cast<duration<f8, micro>>(time_).count(); }
        i8 asUsI() noexcept {return duration_cast<US>(time_).count(); }
        US asUsC() noexcept {return duration_cast<US>(time_); }
        f4 asNsF() noexcept {return duration_cast<duration<f4, nano>>(time_).count(); }
        f8 asNsD() noexcept {return duration_cast<duration<f8, nano>>(time_).count(); }
        i8 asNsI() noexcept {return duration_cast<NS>(time_).count(); }
        NS asNsC() noexcept {return duration_cast<NS>(time_); }
    private:
        nanoseconds time_;
};
class Timer {
public:
    Timer() noexcept : startTime_(sNow()), lastFrameTime_(sNow()) {}
    void Reset() noexcept {startTime_ = lastFrameTime_ = sNow(); }
    /**
     * @brief Measure the time from the start
     */
    Time get() noexcept {
        Time obj(sNow() - startTime_);
        return obj;
    }
    /**
     * @brief Measure the time elapsed since the last call to this function
     */
    Time getDeltaTime() noexcept {
        Time obj(sNow() - lastFrameTime_);
        return obj;
    }
private:
    steady_clock::time_point startTime_; 
    steady_clock::time_point lastFrameTime_;
};
}