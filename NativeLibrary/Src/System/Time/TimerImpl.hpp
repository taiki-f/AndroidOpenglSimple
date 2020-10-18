#pragma once
#include <time.h>

namespace drs { namespace time {

    /// <summary>
    /// タイマーIMPL
    /// </summary>
    class TimerIMPL
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        TimerIMPL() {}

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~TimerIMPL() {}

        /// <summary>
        /// 時間の更新
        /// </summary>
        void UpdateTime() {
            clock_gettime(CLOCK_MONOTONIC, &ts);
        }

        /// <summary>
        /// ミリ秒を取得
        /// </summary>
        u64 GetMilliSec() {
            return (u64)((ts.tv_sec * 1000) + (ts.tv_nsec / 1000000));
        }

        /// <summary>
        /// マイクロ秒を取得
        /// </summary>
        u64 GetMicroSec() {
            return (u64)((ts.tv_sec * 1000000) + (ts.tv_nsec / 1000));
        }

        /// <summary>
        /// ナノ秒を取得
        /// </summary>
        u64 GetNanoSec() {
            return (u64)((ts.tv_sec * 1000000000) + ts.tv_nsec);
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


} } // namespace

