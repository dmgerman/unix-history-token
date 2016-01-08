begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SAFECAST_H
end_ifndef

begin_define
define|#
directive|define
name|SAFECAST_H
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_function
specifier|static
specifier|inline
name|int
name|size2int_chk
parameter_list|(
name|size_t
name|v
parameter_list|)
block|{
if|if
condition|(
name|v
operator|>
name|INT_MAX
condition|)
name|abort
argument_list|()
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
name|v
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|size2int_sat
parameter_list|(
name|size_t
name|v
parameter_list|)
block|{
return|return
operator|(
name|v
operator|>
name|INT_MAX
operator|)
condition|?
name|INT_MAX
else|:
operator|(
name|int
operator|)
name|v
return|;
block|}
end_function

begin_comment
comment|/* Compilers can emit warning about increased alignment requirements  * when casting pointers. The impact is tricky: on machines where  * alignment is just a performance issue (x86,x64,...) this might just  * cause a performance penalty. On others, an address error can occur  * and the process dies...  *  * Still, there are many cases where the pointer arithmetic and the  * buffer alignment make sure this does not happen. OTOH, the compiler  * doesn't know this and still emits warnings.  *  * The following cast macros are going through void pointers to tell  * the compiler that there is no alignment requirement to watch.  */
end_comment

begin_define
define|#
directive|define
name|UA_PTR
parameter_list|(
name|ptype
parameter_list|,
name|pval
parameter_list|)
value|((ptype *)(void*)(pval))
end_define

begin_define
define|#
directive|define
name|UAC_PTR
parameter_list|(
name|ptype
parameter_list|,
name|pval
parameter_list|)
value|((const ptype *)(const void*)(pval))
end_define

begin_define
define|#
directive|define
name|UAV_PTR
parameter_list|(
name|ptype
parameter_list|,
name|pval
parameter_list|)
value|((volatile ptype *)(volatile void*)(pval))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

