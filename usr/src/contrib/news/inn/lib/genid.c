begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_NEED_TIME
argument_list|)
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DO_NEED_TIME) */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_include
include|#
directive|include
file|"libinn.h"
end_include

begin_comment
comment|/* Scale time back a bit, for shorter Message-ID's. */
end_comment

begin_define
define|#
directive|define
name|OFFSET
value|673416000L
end_define

begin_function
name|char
modifier|*
name|GenerateMessageID
parameter_list|()
block|{
specifier|static
name|char
name|buff
index|[
name|SMBUF
index|]
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|char
name|sec32
index|[
literal|10
index|]
decl_stmt|;
name|char
name|pid32
index|[
literal|10
index|]
decl_stmt|;
name|TIMEINFO
name|Now
decl_stmt|;
if|if
condition|(
name|GetTimeInfo
argument_list|(
operator|&
name|Now
argument_list|)
operator|<
literal|0
condition|)
return|return
name|NULL
return|;
name|Radix32
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|Now
operator|.
name|time
operator|-
name|OFFSET
argument_list|,
name|sec32
argument_list|)
expr_stmt|;
name|Radix32
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|getpid
argument_list|()
argument_list|,
name|pid32
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|p
operator|=
name|GetFQDN
argument_list|()
operator|)
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buff
argument_list|,
literal|"<%s$%s@%s>"
argument_list|,
name|sec32
argument_list|,
name|pid32
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
name|buff
return|;
block|}
end_function

end_unit

