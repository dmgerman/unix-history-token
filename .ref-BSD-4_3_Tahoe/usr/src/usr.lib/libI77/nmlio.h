begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)nmlio.h	5.1	7/30/85  */
end_comment

begin_comment
comment|/*	header for namelist I/O */
end_comment

begin_define
define|#
directive|define
name|ERRNM
parameter_list|(
name|x
parameter_list|)
value|if(n=(x)) return(n);
end_define

begin_define
define|#
directive|define
name|VL
value|16
end_define

begin_comment
comment|/* variable name length from f77pass1/defs.h */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|namelistkey_
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|namelistname
index|[
name|VL
operator|+
literal|4
index|]
decl_stmt|;
comment|/* 4 for padding */
struct|struct
name|namelistentry
block|{
name|char
name|varname
index|[
name|VL
operator|+
literal|4
index|]
decl_stmt|;
comment|/* 4 for padding */
name|char
modifier|*
name|varaddr
decl_stmt|;
name|short
name|int
name|type
decl_stmt|;
name|short
name|int
name|typelen
decl_stmt|;
comment|/* 		 * If dimp is not null, then the corner element of the array is 		 * at varaddr.  However,  the element with subscripts: 		 * (i1,...,in) is at 		 * 		 *	varaddr - dimp->baseoffset + sizeoftype * 		 *			((i1-1)+span[0]*((i2-1)+span[1]*...) 		 */
name|int
modifier|*
name|dimp
decl_stmt|;
comment|/* dimension info: (null means scalar) 					*dimp: numb. of dim., 					dimp[0]: number of dimensions 					dimp[1]: total number of elements, 					dimp[2]: base offset, 					dimp[3]: span of 1st dimension 					dimp[4]: span of 2nd dimension 						...			 */
block|}
name|names
index|[
literal|1
index|]
struct|;
comment|/* actually one per name in the namelist */
block|}
name|Namelist
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|flag
name|cierr
decl_stmt|;
name|ftnint
name|ciunit
decl_stmt|;
name|flag
name|ciend
decl_stmt|;
name|Namelist
modifier|*
name|namelist
decl_stmt|;
block|}
name|namelist_arglist
typedef|;
end_typedef

end_unit

