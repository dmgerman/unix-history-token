begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Intel 386 running any BSD Unix */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|O_ACCMODE
end_ifndef

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY | O_WRONLY | O_RDWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
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

begin_define
define|#
directive|define
name|HOST_DATA_START_ADDR
value|((bfd_vma)u.u_kproc.kp_eproc.e_vm.vm_daddr)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This doesn't work in Jolitz release 0.1 */
end_comment

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|USRSTACK
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Found by experimentation. */
end_comment

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|(USRSTACK - MAXSSIZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|MINIMIZE
value|1
end_define

begin_define
define|#
directive|define
name|TRAD_CORE
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULT_VECTOR
value|i386bsd_vec
end_define

begin_define
define|#
directive|define
name|SELECT_ARCHITECTURES
value|bfd_i386_arch
end_define

begin_comment
comment|/* EXACT TYPES */
end_comment

begin_typedef
typedef|typedef
name|char
name|int8e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32e_type
typedef|;
end_typedef

begin_comment
comment|/* CORRECT SIZE OR GREATER */
end_comment

begin_typedef
typedef|typedef
name|char
name|int8_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_type
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"fopen-same.h"
end_include

end_unit

