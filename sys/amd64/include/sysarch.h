begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Architecture specific syscalls (i386)  *  *	$Id$  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_decl_stmt
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

