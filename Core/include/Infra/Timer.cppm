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
/**
 * @brief Obtain time and delta time
 */
class Time {
    public:
        Time() noexcept : time_(0) {}
        Time(nanoseconds time) noexcept : time_(time) {}
        f4 asSecF() const noexcept {return duration_cast<duration<f4>>(time_).count(); }
        f8 asSecD() const noexcept {return duration_cast<duration<f8>>(time_).count(); }
        i8 asSecI() const noexcept {return duration_cast<Sec>(time_).count(); }
        Sec asSecC() const noexcept {return duration_cast<Sec>(time_); }
        f4 asMsF() const noexcept {return duration_cast<duration<f4, milli>>(time_).count(); }
        f8 asMsD() const noexcept {return duration_cast<duration<f8, milli>>(time_).count(); }
        i8 asMsI() const noexcept {return duration_cast<MS>(time_).count(); }
        MS asMsC() const noexcept {return duration_cast<MS>(time_); }
        f4 asUsF() const noexcept {return duration_cast<duration<f4, micro>>(time_).count(); }
        f8 asUsD() const noexcept {return duration_cast<duration<f8, micro>>(time_).count(); }
        i8 asUsI() const noexcept {return duration_cast<US>(time_).count(); }
        US asUsC() const noexcept {return duration_cast<US>(time_); }
        f4 asNsF() const noexcept {return duration_cast<duration<f4, nano>>(time_).count(); }
        f8 asNsD() const noexcept {return duration_cast<duration<f8, nano>>(time_).count(); }
        i8 asNsI() const noexcept {return duration_cast<NS>(time_).count(); }
        NS asNsC() const noexcept {return duration_cast<NS>(time_); }
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
    Time get() const noexcept {return {sNow() - startTime_}; }
    /**
     * @brief Measure the time elapsed since the last call to this function
     */
    Time getDeltaTime() noexcept {
        steady_clock::time_point nowTime = sNow();
        Time time = {nowTime - lastFrameTime_};
        lastFrameTime_ = nowTime;
        return time;
    }
private:
    steady_clock::time_point startTime_; 
    steady_clock::time_point lastFrameTime_;
};
}