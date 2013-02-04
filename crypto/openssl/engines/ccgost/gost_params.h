begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**********************************************************************  *                        gost_params.h                               *  *             Copyright (c) 2005-2006 Cryptocom LTD                  *  *       This file is distributed under the same license as OpenSSL   *  *                                                                    *  *       Declaration of structures used to represent  GOST R 34.10    *  * 	               parameter sets, defined in RFC 4357                *  *         OpenSSL 0.9.9 libraries required to compile and use        *  *                              this code                             *  **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOST_PARAMSET_H
end_ifndef

begin_define
define|#
directive|define
name|GOST_PARAMSET_H
end_define

begin_typedef
typedef|typedef
struct|struct
name|R3410
block|{
name|int
name|nid
decl_stmt|;
name|char
modifier|*
name|a
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|q
decl_stmt|;
block|}
name|R3410_params
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|R3410_params
name|R3410_paramset
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|R3410_2001
block|{
name|int
name|nid
decl_stmt|;
name|char
modifier|*
name|a
decl_stmt|;
name|char
modifier|*
name|b
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|char
modifier|*
name|q
decl_stmt|;
name|char
modifier|*
name|x
decl_stmt|;
name|char
modifier|*
name|y
decl_stmt|;
block|}
name|R3410_2001_params
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|R3410_2001_params
name|R3410_2001_paramset
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

