begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* basic typedefs& defines */
end_comment

begin_comment
comment|/* $Header: imPdefs.h,v 10.2 86/02/01 16:00:23 tony Rel $ */
end_comment

begin_typedef
typedef|typedef
name|short
name|I16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|BDIM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|SDIM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|DISP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|LONGDISP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|RFC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|MSKWORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|GLINK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|SYSCNV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSKSHFT
value|4
end_define

begin_define
define|#
directive|define
name|MSKHIGH
value|15
end_define

begin_define
define|#
directive|define
name|NILPTR
value|0
end_define

begin_define
define|#
directive|define
name|OOPTR
value|((char *)0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|NILIDX
value|-1
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|not
value|~
end_define

begin_define
define|#
directive|define
name|REG
value|register
end_define

begin_define
define|#
directive|define
name|ADVPTR
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|((char *)p+n)
end_define

begin_comment
comment|/* advances pointer 'p' 'n' bytes */
end_comment

begin_define
define|#
directive|define
name|MLIWSIZ
parameter_list|(
name|w
parameter_list|)
value|((w+15)>>4)
end_define

begin_define
define|#
directive|define
name|MLIBSIZ
parameter_list|(
name|w
parameter_list|)
value|((w+7)>>3)
end_define

begin_define
define|#
directive|define
name|MSKWSIZ
parameter_list|(
name|w
parameter_list|,
name|h
parameter_list|)
value|(MLIWSIZ(w)*h)
end_define

begin_define
define|#
directive|define
name|SMWSIZ
parameter_list|(
name|p
parameter_list|)
value|MSKWSIZ(p->sgw,p->sgh)
end_define

begin_define
define|#
directive|define
name|BMWSIZ
parameter_list|(
name|p
parameter_list|)
value|MSKWSIZ(p->bgw,p->bgh)
end_define

begin_define
define|#
directive|define
name|GVWSIZ
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|)
value|(t==SMALL ? SGDWSIZ+SMWSIZ(((sgdims *)(p))) : \ 				BGDWSIZ+BMWSIZ(((bgdims *)(p)))	\ 			)
end_define

begin_define
define|#
directive|define
name|GLYWSIZ
parameter_list|(
name|p
parameter_list|)
value|(GHWSIZ+GVWSIZ(p->gsize,(char *)(p)+GHBSIZ))
end_define

begin_define
define|#
directive|define
name|GPRECOMP
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|)
value|(((r<<14)|(f<<7)) % GHTLEN)
end_define

begin_comment
comment|/* not used by imPRESS */
end_comment

begin_define
define|#
directive|define
name|GPREHASH
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|)
value|gprehtab[(r<<7)|f]
end_define

begin_define
define|#
directive|define
name|GHASHIX
parameter_list|(
name|rfc
parameter_list|)
value|gprehtab[(rfc>>7)&0777] + (rfc&0177)
end_define

begin_define
define|#
directive|define
name|FNAMLEN
value|8
end_define

begin_typedef
typedef|typedef
union|union
block|{
comment|/******** DECODE PARAMETERS ***********/
name|BDIM
name|pval
decl_stmt|;
comment|/* parameter value		      */
struct|struct
block|{
ifdef|#
directive|ifdef
name|XWIND
name|char
name|loval
decl_stmt|;
name|char
name|hival
decl_stmt|;
else|#
directive|else
name|char
name|hival
decl_stmt|;
name|char
name|loval
decl_stmt|;
endif|#
directive|endif
block|}
name|pval2
struct|;
name|char
modifier|*
name|pptr
decl_stmt|;
comment|/* parameter address (w/input area)   */
block|}
name|parva
typedef|;
end_typedef

begin_comment
comment|/**************************************/
end_comment

begin_decl_stmt
name|parva
name|param
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|V
parameter_list|(
name|i
parameter_list|)
value|(param[i].pval)
end_define

begin_define
define|#
directive|define
name|v
parameter_list|(
name|i
parameter_list|)
value|(param[i].pval2.loval)
end_define

begin_define
define|#
directive|define
name|P
parameter_list|(
name|i
parameter_list|)
value|(param[i].pptr)
end_define

begin_comment
comment|/* extend sign for an int */
end_comment

begin_define
define|#
directive|define
name|EXTSIGN
parameter_list|(
name|n
parameter_list|)
value|if (v(n)<0) param[n].pval2.hival = 0377
end_define

end_unit

