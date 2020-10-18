#pragma once
#include <time.h>

namespace drs { namespace time {

    /// <summary>
    /// �^�C�}�[IMPL
    /// </summary>
    class TimerIMPL
    {
    public:
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        TimerIMPL() {}

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~TimerIMPL() {}

        /// <summary>
        /// ���Ԃ̍X�V
        /// </summary>
        void UpdateTime() {
            clock_gettime(CLOCK_MONOTONIC, &ts);
        }

        /// <summary>
        /// �~���b���擾
        /// </summary>
        u64 GetMilliSec() {
            return (u64)((ts.tv_sec * 1000) + (ts.tv_nsec / 1000000));
        }

        /// <summary>
        /// �}�C�N���b���擾
        /// </summary>
        u64 GetMicroSec() {
            return (u64)((ts.tv_sec * 1000000) + (ts.tv_nsec / 1000));
        }

        /// <summary>
        /// �i�m�b���擾
        /// </summary>
        u64 GetNanoSec() {
            return (u64)((ts.tv_sec * 1000000000) + ts.tv_nsec);
        }

        /// <summary>
        /// ���Ԃ̃N���A
        /// </summary>
        void ClearTime() {
            ts.tv_sec = 0;
            ts.tv_nsec = 0;
        }

        // ���Ԏ擾�p
        timespec ts;
    };


} } // namespace

