begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LANGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LANGINFO_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|YESEXPR
value|1
end_define

begin_comment
comment|/* xargs only needs yesexpr, so that's all we implement, for english */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|nl_langinfo
parameter_list|(
name|int
name|type
name|__unused
parameter_list|)
block|{
return|return
operator|(
literal|"^[yY]"
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LANGINFO_H */
end_comment

end_unit

