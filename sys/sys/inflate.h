begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Parts of this file are not covered by:  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: imgact_gzip.c,v 1.4 1994/10/04 06:51:42 phk Exp $  *  * This module handles execution of a.out files which have been run through  * "gzip -9".  *  * For now you need to use exactly this command to compress the binaries:  *  *		gzip -9 -v< /bin/sh> /tmp/sh  *  * TODO:  *	text-segments should be made R/O after being filled  *	is the vm-stuff safe ?  * 	should handle the entire header of gzip'ed stuff.  *	inflate isn't quite reentrant yet...  *	error-handling is a mess...  *	so is the rest...  *	tidy up unnecessary includes  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_INFLATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_INFLATE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/resourcevar.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/imgact.h>
end_include

begin_include
include|#
directive|include
file|<sys/imgact_aout.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_define
define|#
directive|define
name|WSIZE
value|0x8000
end_define

begin_struct
struct|struct
name|gzip
block|{
name|struct
name|image_params
modifier|*
name|ip
decl_stmt|;
name|struct
name|exec
name|a_out
decl_stmt|;
name|int
name|error
decl_stmt|;
name|int
name|where
decl_stmt|;
name|u_char
modifier|*
name|inbuf
decl_stmt|;
name|u_long
name|offset
decl_stmt|;
name|u_long
name|output
decl_stmt|;
name|u_long
name|len
decl_stmt|;
name|int
name|idx
decl_stmt|;
name|u_long
name|virtual_offset
decl_stmt|,
name|file_offset
decl_stmt|,
name|file_end
decl_stmt|,
name|bss_size
decl_stmt|;
name|unsigned
name|gz_wp
decl_stmt|;
name|u_char
modifier|*
name|gz_slide
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Global variables used by inflate and friends.  * This structure is used in order to make inflate() reentrant.  */
end_comment

begin_struct
struct|struct
name|gz_global
block|{
name|int
name|foo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|inflate
name|__P
argument_list|(
operator|(
expr|struct
name|gzip
operator|*
operator|,
expr|struct
name|gz_global
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|slide
value|(gz->gz_slide)
end_define

begin_define
define|#
directive|define
name|wp
value|(gz->gz_wp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SYS_INFLATE_H_ */
end_comment

end_unit

