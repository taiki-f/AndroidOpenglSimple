#pragma once

#include "Types.h"
#include <memory>

namespace drs { namespace time {

    class TimerIMPL;

    /// <summary>
    /// �^�C�}�[
    /// </summary>
    class Timer
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Timer();
        Timer(const Timer& t) = delete;
        Timer(Timer&& t) = delete;

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~Timer();

        /// <summary>
        /// ������Z�q�̃I�[�o�[���C�h
        /// </summary>
        Timer& operator=(const Timer& t) = delete;
        Timer& operator=(Timer&& t) = delete;

        /// <summary>
        /// �~���b���擾
        /// </summary>
        u64 GetMilliSec();

        /// <summary>
        /// �}�C�N���b���擾
        /// </summary>
        u64 GetMicroSec();

        /// <summary>
        /// �i�m�b���擾
        /// </summary>
        u64 GetNanoSec();

    protected:
        TimerIMPL* impl;
    };
} } // namespace
