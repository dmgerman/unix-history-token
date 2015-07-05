begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<ntp.h>
end_include

begin_include
include|#
directive|include
file|<ntp_fp.h>
end_include

begin_include
include|#
directive|include
file|<refidsmear.h>
end_include

begin_comment
comment|/*  * we want to test a refid format of:  * 254.x.y.x  *  * where x.y.z are 24 bits containing 2 (signed) integer bits  * and 22 fractional bits.  *  */
end_comment

begin_function
name|l_fp
name|convertRefIDToLFP
parameter_list|(
name|uint32_t
name|r
parameter_list|)
block|{
name|l_fp
name|temp
decl_stmt|;
name|r
operator|=
name|ntohl
argument_list|(
name|r
argument_list|)
expr_stmt|;
comment|// printf("%03d %08x: ", (r>> 24)& 0xFF, (r& 0x00FFFFFF) );
name|temp
operator|.
name|l_uf
operator|=
operator|(
name|r
operator|<<
literal|10
operator|)
expr_stmt|;
comment|/* 22 fractional bits */
name|temp
operator|.
name|l_ui
operator|=
operator|(
name|r
operator|>>
literal|22
operator|)
operator|&
literal|0x3
expr_stmt|;
name|temp
operator|.
name|l_ui
operator||=
operator|~
operator|(
name|temp
operator|.
name|l_ui
operator|&
literal|2
operator|)
operator|+
literal|1
expr_stmt|;
return|return
name|temp
return|;
block|}
end_function

begin_function
name|uint32_t
name|convertLFPToRefID
parameter_list|(
name|l_fp
name|num
parameter_list|)
block|{
name|uint32_t
name|temp
decl_stmt|;
comment|/* round the input with the highest bit to shift out from the 	 * fraction, then keep just two bits from the integral part. 	 * 	 * TODO: check for overflows; should we clamp/saturate or just 	 * complain? 	 */
name|L_ADDUF
argument_list|(
operator|&
name|num
argument_list|,
literal|0x200
argument_list|)
expr_stmt|;
name|num
operator|.
name|l_ui
operator|&=
literal|3
expr_stmt|;
comment|/* combine integral and fractional part to 24 bits */
name|temp
operator|=
operator|(
name|num
operator|.
name|l_ui
operator|<<
literal|22
operator|)
operator||
operator|(
name|num
operator|.
name|l_uf
operator|>>
literal|10
operator|)
expr_stmt|;
comment|/* put in the leading 254.0.0.0 */
name|temp
operator||=
name|UINT32_C
argument_list|(
literal|0xFE000000
argument_list|)
expr_stmt|;
comment|// printf("%03d %08x: ", (temp>> 24)& 0xFF, (temp& 0x00FFFFFF) );
return|return
name|htonl
argument_list|(
name|temp
argument_list|)
return|;
block|}
end_function

end_unit

