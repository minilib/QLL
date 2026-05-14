#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#define NOSERVICE
#define NOMCX
#define NOIME
#define NOSOUND
#define NOCOMM
#define NOKANJI
#define NORPC
#define NOGDI
#define NOUSER
#include <Windows.h>
export module FLL.Base.Timer;
import FLL.Core.Types;
import std;
using namespace std::chrono;
export namespace FLL {
    class Timer {
    public:
        Timer() noexcept : startTime_(steady_clock::now()), lastFrameTime_(steady_clock::now()) {};
        void Reset() {}
        f4 GetTime() const;      // 秒単位の経過時間
        f4 GetDeltaTime() const; // 前フレームからの経過時間

    private:
        steady_clock::time_point startTime_; 
        steady_clock::time_point lastFrameTime_;
    };
}