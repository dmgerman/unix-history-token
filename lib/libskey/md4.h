begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__ARGS
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_comment
comment|/* For ANSI C */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ARGS
parameter_list|(
name|X
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   *  * md4.h -- Header file for implementation of MD4 Message Digest Algorithm  * Updated: 2/13/90 by Ronald L. Rivest  * (C) 1990 RSA Data Security, Inc.  * Reformatted and de-linted - 2/12/91 Phil Karn  */
end_comment

begin_comment
comment|/* MDstruct is the data structure for a message digest computation. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|buffer
index|[
literal|4
index|]
decl_stmt|;
comment|/* Holds 4-word result of MD computation */
name|unsigned
name|char
name|count
index|[
literal|8
index|]
decl_stmt|;
comment|/* Number of bits processed so far */
name|unsigned
name|int
name|done
decl_stmt|;
comment|/* Nonzero means MD computation finished */
block|}
name|MDstruct
operator|,
typedef|*
name|MDptr
typedef|;
end_typedef

begin_comment
comment|/* MDbegin(MD)  * Input: MD -- an MDptr  * Initialize the MDstruct prepatory to doing a message digest computation.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|MDbegin
name|__ARGS
argument_list|(
operator|(
name|MDptr
name|MDp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MDupdate(MD,X,count)  * Input: MD -- an MDptr  *        X -- a pointer to an array of unsigned characters.  *        count -- the number of bits of X to use (an unsigned int).  * Updates MD using the first ``count'' bits of X.  * The array pointed to by X is not modified.  * If count is not a multiple of 8, MDupdate uses high bits of last byte.  * This is the basic input routine for a user.  * The routine terminates the MD computation when count< 512, so  * every MD computation should end with one call to MDupdate with a  * count less than 512.  Zero is OK for a count.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|MDupdate
name|__ARGS
argument_list|(
operator|(
name|MDptr
name|MDp
operator|,
name|unsigned
name|char
operator|*
name|X
operator|,
name|unsigned
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MDprint(MD)  * Input: MD -- an MDptr  * Prints message digest buffer MD as 32 hexadecimal digits.  * Order is from low-order byte of buffer[0] to high-order byte of buffer[3].  * Each byte is printed with high-order hexadecimal digit first.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|MDprint
name|__ARGS
argument_list|(
operator|(
name|MDptr
name|MDp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* End of md4.h */
end_comment

end_unit

