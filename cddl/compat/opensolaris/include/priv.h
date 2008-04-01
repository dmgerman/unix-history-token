begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_PRIV_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_PRIV_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|PRIV_SYS_CONFIG
value|0
end_define

begin_function
specifier|static
name|__inline
name|int
name|priv_ineffect
parameter_list|(
name|priv
parameter_list|)
block|{
name|assert
argument_list|(
name|priv
operator|==
name|PRIV_SYS_CONFIG
argument_list|)
expr_stmt|;
return|return
operator|(
name|geteuid
argument_list|()
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_PRIV_H_ */
end_comment

end_unit

