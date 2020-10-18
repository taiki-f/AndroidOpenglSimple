#pragma once

#include "Types.h"
#include <memory>

namespace drs { namespace time {

    class TimerIMPL;

    /// <summary>
    /// タイマー
    /// </summary>
    class Timer
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Timer();
        Timer(const Timer& t) = delete;
        Timer(Timer&& t) = delete;

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~Timer();

        /// <summary>
        /// 代入演算子のオーバーライド
        /// </summary>
        Timer& operator=(const Timer& t) = delete;
        Timer& operator=(Timer&& t) = delete;

        /// <summary>
        /// ミリ秒を取得
        /// </summary>
        u64 GetMilliSec();

        /// <summary>
        /// マイクロ秒を取得
        /// </summary>
        u64 GetMicroSec();

        /// <summary>
        /// ナノ秒を取得
        /// </summary>
        u64 GetNanoSec();

    protected:
        TimerIMPL* impl;
    };
} } // namespace
