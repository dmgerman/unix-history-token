begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Architecture specific syscalls (i386)  *  *	$Id: sysarch.h,v 1.2 1993/10/16 14:39:35 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SYSARCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SYSARCH_H_
value|1
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|I386_GET_LDT
value|0
end_define

begin_define
define|#
directive|define
name|I386_SET_LDT
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* nothing here yet... */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not KERNEL */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|i386_get_ldt
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|union
name|descriptor
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i386_set_ldt
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|union
name|descriptor
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SYSARCH_H_ */
end_comment

end_unit

