#pragma once

#include "Time/Timer.hpp"

namespace drs {  namespace time {

    /// <summary>
    /// FPSタイマー
    /// </summary>
    class FPSTimer : public Timer
    {
    public:
        /// <summary>
        /// コンストラクタ
        /// </summary>
        FPSTimer();

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~FPSTimer();
    };

} } // namespace
