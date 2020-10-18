#include "TimerImpl.hpp"
#include "Timer.hpp"

namespace drs { namespace time {

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Timer::Timer()
        : impl(new TimerIMPL())
    {}

    /// <summary>
    /// デストラクタ
    /// </summary>
    Timer::~Timer()
    {
        delete impl;
    }

    /// <summary>
    /// ミリ秒を取得
    /// </summary>
    u64 Timer::GetMilliSec()
    {
        impl->UpdateTime();
        return impl->GetMilliSec();
    }

    /// <summary>
    /// マイクロ秒を取得
    /// </summary>
    u64 Timer::GetMicroSec()
    {
        impl->UpdateTime();
        return impl->GetMicroSec();
    }

    /// <summary>
    /// ナノ秒を取得
    /// </summary>
    u64 Timer::GetNanoSec()
    {
        impl->UpdateTime();
        return impl->GetNanoSec();
    }

} } // namespace
