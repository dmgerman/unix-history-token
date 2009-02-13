begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ntp_types.h>
end_include

begin_decl_stmt
name|long
name|ntp_random
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ntp_srandom
name|P
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ntp_srandomdev
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ntp_initstate
name|P
argument_list|(
operator|(
name|unsigned
name|long
operator|,
comment|/* seed for R.N.G. */
name|char
operator|*
operator|,
comment|/* pointer to state array */
name|long
comment|/* # bytes of state info */
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ntp_setstate
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to state array */
end_comment

end_unit

