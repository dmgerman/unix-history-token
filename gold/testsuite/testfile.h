begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// testfile.h -- test input files   -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_TESTSUITE_TESTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_TESTSUITE_TESTFILE_H
end_define

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|Target
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|gold_testsuite
block|{
extern|extern gold::Target* target_test_pointer;
specifier|extern
specifier|const
name|unsigned
name|char
name|test_file_1
index|[]
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|int
name|test_file_1_size
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// End namespace gold_testsuite.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_TESTSUITE_TESTFILE_H)
end_comment

end_unit

