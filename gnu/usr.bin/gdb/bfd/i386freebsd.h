begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Intel 386 running any FreeBSD Unix */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_define
define|#
directive|define
name|NBPG
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|HOST_PAGE_SIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|HOST_MACHINE_ARCH
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|HOST_TEXT_START_ADDR
value|USRTEXT
end_define

begin_comment
comment|/* Jolitz suggested defining HOST_STACK_END_ADDR to    (u.u_kproc.kp_eproc.e_vm.vm_maxsaddr + MAXSSIZ), which should work on    both BSDI and 386BSD, but that is believed not to work for BSD 4.4.  */
end_comment

begin_comment
comment|/* This seems to be the right thing for FreeBSD and BSDI */
end_comment

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|USRSTACK
end_define

begin_comment
comment|/* Leave HOST_DATA_START_ADDR undefined, since the default when it is not    defined sort of works, and FreeBSD-2.0 through FreeBSD-2.2.2 do not    set u.u_kproc.kp_eproc.e_vm.vm_daddr.  */
end_comment

begin_define
define|#
directive|define
name|TRAD_UNIX_CORE_FILE_FAILING_SIGNAL
parameter_list|(
name|core_bfd
parameter_list|)
define|\
value|((core_bfd)->tdata.trad_core_data->u.u_sig)
end_define

begin_define
define|#
directive|define
name|u_comm
value|u_kproc.kp_proc.p_comm
end_define

end_unit

