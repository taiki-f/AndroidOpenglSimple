#include "Timer.hpp"
#include <time.h>

namespace drs { namespace time {

    /// <summary>
    /// PImpl�C�f�I��
    /// </summary>
    struct Timer::Impl {
        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Impl() {}

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Impl() {}

        /// <summary>
        /// ���Ԃ̍X�V
        /// </summary>
        void UpdateTime() {
            clock_gettime(CLOCK_MONOTONIC, &ts);
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

    /// <summary>
    /// �R���X�g���N�^
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
    /// ������Z�q�̃I�[�o�[���C�h
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
    /// �f�X�g���N�^
    /// </summary>
    Timer::~Timer()
    {
        delete impl;
    }

    /// <summary>
    /// �~���b���擾
    /// </summary>
    u64 Timer::GetMilliSec()
    {
        impl->UpdateTime();
        return (u64)((impl->ts.tv_sec * 1000) + (impl->ts.tv_nsec / 1000000));
    }

    /// <summary>
    /// �}�C�N���b���擾
    /// </summary>
    u64 Timer::GetMicroSec()
    {
        impl->UpdateTime();
        return (u64)((impl->ts.tv_sec * 1000000) + (impl->ts.tv_nsec / 1000));
    }

    /// <summary>
    /// �i�m�b���擾
    /// </summary>
    u64 Timer::GetNanoSec()
    {
        impl->UpdateTime();
        return (u64)((impl->ts.tv_sec * 1000000000) + impl->ts.tv_nsec);
    }

} } // namespace
