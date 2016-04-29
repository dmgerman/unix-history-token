begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_include
include|#
directive|include
file|"openssl/err.h"
end_include

begin_include
include|#
directive|include
file|"openssl/rand.h"
end_include

begin_include
include|#
directive|include
file|"openssl/evp.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"unity.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|TEST_MD5_DIGEST_LENGTH
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|TEST_SHA1_DIGEST_LENGTH
init|=
literal|20
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|test_MD5KeyTypeWithoutDigestLength
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_MD5KeyTypeWithDigestLength
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_SHA1KeyTypeWithDigestLength
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_MD5KeyName
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_SHA1KeyName
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// keytype_from_text()
end_comment

begin_function
name|void
name|test_MD5KeyTypeWithoutDigestLength
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL
argument_list|(
name|KEY_TYPE_MD5
argument_list|,
name|keytype_from_text
argument_list|(
literal|"MD5"
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_MD5KeyTypeWithDigestLength
parameter_list|(
name|void
parameter_list|)
block|{
name|size_t
name|digestLength
decl_stmt|;
name|size_t
name|expected
init|=
name|TEST_MD5_DIGEST_LENGTH
decl_stmt|;
name|TEST_ASSERT_EQUAL
argument_list|(
name|KEY_TYPE_MD5
argument_list|,
name|keytype_from_text
argument_list|(
literal|"MD5"
argument_list|,
operator|&
name|digestLength
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_ASSERT_EQUAL
argument_list|(
name|expected
argument_list|,
name|digestLength
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_SHA1KeyTypeWithDigestLength
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|OPENSSL
name|size_t
name|digestLength
decl_stmt|;
name|size_t
name|expected
init|=
name|TEST_SHA1_DIGEST_LENGTH
decl_stmt|;
name|TEST_ASSERT_EQUAL
argument_list|(
name|NID_sha1
argument_list|,
name|keytype_from_text
argument_list|(
literal|"SHA1"
argument_list|,
operator|&
name|digestLength
argument_list|)
argument_list|)
expr_stmt|;
name|TEST_ASSERT_EQUAL
argument_list|(
name|expected
argument_list|,
name|digestLength
argument_list|)
expr_stmt|;
comment|/* OPENSSL */
else|#
directive|else
name|TEST_IGNORE_MESSAGE
argument_list|(
literal|"Skipping because OPENSSL isn't defined"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// keytype_name()
end_comment

begin_function
name|void
name|test_MD5KeyName
parameter_list|(
name|void
parameter_list|)
block|{
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"MD5"
argument_list|,
name|keytype_name
argument_list|(
name|KEY_TYPE_MD5
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_SHA1KeyName
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|OPENSSL
name|TEST_ASSERT_EQUAL_STRING
argument_list|(
literal|"SHA1"
argument_list|,
name|keytype_name
argument_list|(
name|NID_sha1
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|TEST_IGNORE_MESSAGE
argument_list|(
literal|"Skipping because OPENSSL isn't defined"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* OPENSSL */
block|}
end_function

end_unit

