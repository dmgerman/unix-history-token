begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* popauth.h - POP authorization DB definitions */
end_comment

begin_comment
comment|/* @(#)$Id: popauth.h,v 1.1 1992/02/11 17:41:39 jromine Exp $ */
end_comment

begin_struct
struct|struct
name|authinfo
block|{
name|char
name|auth_secret
index|[
literal|16
index|]
decl_stmt|;
name|int
name|auth_secretlen
decl_stmt|;
block|}
struct|;
end_struct

end_unit

