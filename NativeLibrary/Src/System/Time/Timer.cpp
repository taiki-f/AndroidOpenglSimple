#include "Timer.hpp"
#include <time.h>

namespace drs { namespace time {

    /// <summary>
    /// PImplイデオム
    /// </summary>
    struct Timer::Impl {
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Impl() {}

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Impl() {}

        /// <summary>
        /// 時間の更新
        /// </summary>
        void UpdateTime() {
            clock_gettime(CLOCK_MONOTONIC, &ts);
        }

        /// <summary>
        /// 時間のクリア
        /// </summary>
        void ClearTime() {
            ts.tv_sec = 0;
            ts.tv_nsec = 0;
        }

        // 時間取得用
        timespec ts;
    };

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Timer::Timer()
        : impl(new Impl())
    {}
    Timer::Timer(const Timer& t)
    {
        impl = new Impl();
        impl->ts = t.impl->ts;
    }
    Timer::Timer(Timer&& t)
    {
        impl = new Impl();
        impl->ts = t.impl->ts;
        impl->ClearTime();
    }

    /// <summary>
    /// 代入演算子のオーバーライド
    /// </summary>
    Timer& Timer::operator=(const Timer& t)
    {
        if (this != &t)
        {
            impl->ts = t.impl->ts;
        }
        return *this;
    }
    Timer& Timer::operator=(Timer&& t)
    {
        if (this != &t)
        {
            impl->ts = t.impl->ts;
            impl->ClearTime();
        }
        return *this;
    }

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
        return (u64)((impl->ts.tv_sec * 1000) + (impl->ts.tv_nsec / 1000000));
    }

    /// <summary>
    /// マイクロ秒を取得
    /// </summary>
    u64 Timer::GetMicroSec()
    {
        impl->UpdateTime();
        return (u64)((impl->ts.tv_sec * 1000000) + (impl->ts.tv_nsec / 1000));
    }

    /// <summary>
    /// ナノ秒を取得
    /// </summary>
    u64 Timer::GetNanoSec()
    {
        impl->UpdateTime();
        return (u64)((impl->ts.tv_sec * 1000000000) + impl->ts.tv_nsec);
    }

} } // namespace
