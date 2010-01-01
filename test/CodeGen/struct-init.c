begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_typedef
typedef|typedef
name|struct
name|_zend_ini_entry
name|zend_ini_entry
typedef|;
end_typedef

begin_struct
struct|struct
name|_zend_ini_entry
block|{
name|void
modifier|*
name|mh_arg1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|a
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|zend_ini_entry
name|ini_entries
index|[]
init|=
block|{
block|{
operator|(
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
operator|(
name|zend_ini_entry
operator|*
operator|)
literal|0
operator|)
operator|->
name|mh_arg1
operator|-
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
literal|0
operator|)
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

