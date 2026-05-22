// SPDX-License-Identifier: MIT OR Apache-2.0
export module FLL.Core.Base.Timer;
import FLL.Core.Base.Types;
import std;
using namespace std;
using namespace chrono;
inline steady_clock::time_point sNow() {return steady_clock::now(); }
namespace FLL {
    using NS = nanoseconds;
    using US = microseconds;
    using MS = milliseconds;
    using Sec = seconds;
};
export namespace FLL {
    class Time {
        public:
            Time() noexcept : time_(0) {}
            long long asSecF() {return duration_cast<seconds>(time_)}
            long long asSecI() {return duration_cast<seconds>(time_)}
        private:
            nanoseconds time_;
    };
    class Timer {
    public:
        template <typename DurationType>
            typename DurationType::rep getElapsed() const noexcept {
            return duration_cast<DurationType>(sNow() - startTime_).count();
        }
        template <typename DurationType>
            typename DurationType::rep getDeltaElapsed() noexcept {
            steady_clock::time_point now = sNow();
            DurationType duration = duration_cast<DurationType>(now - lastFrameTime_).count();
            lastFrameTime_ = now;
            return duration;
        }
        Timer() noexcept : startTime_(sNow()), lastFrameTime_(sNow()) {}
        void Reset() noexcept {startTime_ = lastFrameTime_ = sNow(); }
        long long ns() const noexcept {return getElapsed<NS>(); }
        long long us() const noexcept {return getElapsed<US>(); }
        long long ms() const noexcept {return getElapsed<MS>(); }
        long long sec() const noexcept {return getElapsed<Sec>(); }

        float nsF() const noexcept {return getElapsed<duration<float, std::nano>>(); }
        float usF() const noexcept {return getElapsed<duration<float, std::micro>>(); }
        float msF() const noexcept {return getElapsed<duration<float, std::milli>>(); }
        float secF() const noexcept {return getElapsed<duration<float>>(); }

        double nsD() const noexcept {return getElapsed<duration<double, std::nano>>(); }
        double usD() const noexcept {return getElapsed<duration<double, std::micro>>(); }
        double msD() const noexcept {return getElapsed<duration<double, std::milli>>(); }
        double secD() const noexcept {return getElapsed<duration<double>>(); }

        NS  nsC() const noexcept {return duration_cast<NS>(sNow() - startTime_); }
        US usC() const noexcept {return duration_cast<US>(sNow() - startTime_); }
        MS msC() const noexcept {return duration_cast<MS>(sNow() - startTime_); }
        Sec secC() const noexcept {return duration_cast<Sec>(sNow() - startTime_); }

        long long deltaNs() const noexcept {return getElapsed<NS>(); }
        long long deltaUs() const noexcept {return getElapsed<US>(); }
        long long deltaMs() const noexcept {return getElapsed<MS>(); }
        long long deltaSec() const noexcept {return getElapsed<Sec>(); }

        float deltaNsF() const noexcept {return getElapsed<duration<float, std::nano>>(); }
        float deltaUsF() const noexcept {return getElapsed<duration<float, std::micro>>(); }
        float deltaMsF() const noexcept {return getElapsed<duration<float, std::milli>>(); }
        float deltaSecF() const noexcept {return getElapsed<duration<float>>(); }

        double deltaNsD() const noexcept {return getElapsed<duration<double, std::nano>>(); }
        double deltaUsD() const noexcept {return getElapsed<duration<double, std::micro>>(); }
        double deltaMsD() const noexcept {return getElapsed<duration<double, std::milli>>(); }
        double deltaSecD() const noexcept {return getElapsed<duration<double>>(); }

        NS deltaNsC() const noexcept {return duration_cast<NS>(sNow() - startTime_); }
        US deltaUsC() const noexcept {return duration_cast<US>(sNow() - startTime_); }
        MS delatMsC() const noexcept {return duration_cast<MS>(sNow() - startTime_); }
        Sec deltaSecC() const noexcept {return duration_cast<Sec>(sNow() - startTime_); }
    private:
        steady_clock::time_point startTime_; 
        steady_clock::time_point lastFrameTime_;
    };
}