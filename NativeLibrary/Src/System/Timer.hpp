#pragma once

#include "Types.h"
#include <memory>

namespace drs { namespace time {

    /// <summary>
    /// タイマークラス
    /// </summary>
    class Timer
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        Timer();
        Timer(const Timer& t);
        Timer(Timer&& t);

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~Timer();

        /// <summary>
        /// 代入演算子のオーバーライド
        /// </summary>
        Timer& operator=(const Timer& t);
        Timer& operator=(Timer&& t);

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

        // PIMPLイデオム
    private:
        struct Impl;
        Impl* impl;
    protected:
        Impl* IMPL() {
            return impl;
        }
    };
} } // namespace
