#pragma once

#include "Time/Timer.hpp"

namespace drs {  namespace time {

    /// <summary>
    /// FPS�^�C�}�[
    /// </summary>
    class FPSTimer : public Timer
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        FPSTimer();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~FPSTimer();
    };

} } // namespace
