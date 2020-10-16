#pragma once

#include "Types.h"
#include <memory>

namespace drs { namespace time {

    /// <summary>
    /// �^�C�}�[�N���X
    /// </summary>
    class Timer
    {
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

        // PIMPL�C�f�I��
    private:
        struct Impl;
        Impl* impl;
    protected:
        Impl* IMPL() {
            return impl;
        }
    };
} } // namespace
