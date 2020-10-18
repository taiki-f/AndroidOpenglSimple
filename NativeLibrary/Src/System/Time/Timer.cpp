#include "TimerImpl.hpp"
#include "Timer.hpp"

namespace drs { namespace time {

    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Timer::Timer()
        : impl(new TimerIMPL())
    {}

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
        return impl->GetMilliSec();
    }

    /// <summary>
    /// �}�C�N���b���擾
    /// </summary>
    u64 Timer::GetMicroSec()
    {
        impl->UpdateTime();
        return impl->GetMicroSec();
    }

    /// <summary>
    /// �i�m�b���擾
    /// </summary>
    u64 Timer::GetNanoSec()
    {
        impl->UpdateTime();
        return impl->GetNanoSec();
    }

} } // namespace
