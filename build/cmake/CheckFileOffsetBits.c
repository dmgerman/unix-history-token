begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|KB
value|((off_t)1024)
end_define

begin_define
define|#
directive|define
name|MB
value|((off_t)1024 * KB)
end_define

begin_define
define|#
directive|define
name|GB
value|((off_t)1024 * MB)
end_define

begin_define
define|#
directive|define
name|TB
value|((off_t)1024 * GB)
end_define

begin_decl_stmt
name|int
name|t2
index|[
operator|(
operator|(
operator|(
literal|64
operator|*
name|GB
operator|-
literal|1
operator|)
operator|%
literal|671088649
operator|)
operator|==
literal|268434537
operator|)
operator|&&
operator|(
operator|(
operator|(
name|TB
operator|-
operator|(
literal|64
operator|*
name|GB
operator|-
literal|1
operator|)
operator|+
literal|255
operator|)
operator|%
literal|1792151290
operator|)
operator|==
literal|305159546
operator|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

