begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_ATOMIC_H__
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|unsigned
name|int
name|val
decl_stmt|;
block|}
name|atomic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|atomic_read
parameter_list|(
name|v
parameter_list|)
value|((v)->val)
end_define

begin_define
define|#
directive|define
name|atomic_set
parameter_list|(
name|v
parameter_list|,
name|i
parameter_list|)
value|((v)->val = (i))
end_define

begin_define
define|#
directive|define
name|atomic_add
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|atomic_add_int(&(v)->val, (i))
end_define

begin_define
define|#
directive|define
name|atomic_inc
parameter_list|(
name|v
parameter_list|)
value|atomic_add_int(&(v)->val, 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|v
parameter_list|)
value|atomic_subtract_int(&(v)->val, 1)
end_define

begin_define
define|#
directive|define
name|atomic_sub
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|atomic_subtract_int(&(v)->val, (i))
end_define

begin_define
define|#
directive|define
name|atomic_dec_and_test
parameter_list|(
name|v
parameter_list|)
value|(atomic_fetchadd_int(&(v)->val, -1) == 1)
end_define

begin_comment
comment|/*  * This is used for two variables in XFS, one of which is a debug trace  * buffer index.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|atomicIncWithWrap
parameter_list|(
specifier|volatile
name|unsigned
name|int
modifier|*
name|ip
parameter_list|,
name|int
name|val
parameter_list|)
block|{
name|unsigned
name|int
name|oldval
decl_stmt|,
name|newval
decl_stmt|;
do|do
block|{
name|oldval
operator|=
operator|*
name|ip
expr_stmt|;
name|newval
operator|=
operator|(
name|oldval
operator|+
literal|1
operator|>=
name|val
operator|)
condition|?
literal|0
else|:
name|oldval
operator|+
literal|1
expr_stmt|;
block|}
do|while
condition|(
name|atomic_cmpset_rel_int
argument_list|(
name|ip
argument_list|,
name|oldval
argument_list|,
name|newval
argument_list|)
operator|==
literal|0
condition|)
do|;
return|return
name|oldval
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_ATOMIC_H__ */
end_comment

end_unit

