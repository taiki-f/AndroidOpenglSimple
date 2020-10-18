#pragma once

#include "Types.h"
#include <memory>

namespace drs { namespace time {

    /// <summary>
    /// �^�C�}�[
    /// </summary>
    class Timer
    {
        // PIMPL�C�f�I��
    protected:
        struct Impl;

    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Timer();
        Timer(const Timer& t);
        Timer(Timer&& t);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~Timer();

        /// <summary>
        /// ������Z�q�̃I�[�o�[���C�h
        /// </summary>
        Timer& operator=(const Timer& t);
        Timer& operator=(Timer&& t);

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
        Impl* impl;
    };
} } // namespace
