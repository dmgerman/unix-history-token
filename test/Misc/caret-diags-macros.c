begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s> %t 2>&1
end_comment

begin_define
define|#
directive|define
name|M1
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_comment
comment|// RUN: grep ":6:12: note: instantiated from:" %t
end_comment

begin_define
define|#
directive|define
name|M2
value|1;
end_define

begin_function
name|void
name|foo
parameter_list|()
block|{
comment|// RUN: grep ":10:2: warning: expression result unused" %t
name|M1
argument_list|(
comment|// RUN: grep ":12:5: note: instantiated from:" %t
argument|M2
argument_list|)
block|}
end_function

begin_comment
comment|// RUN: grep ":16:11: note: instantiated from:" %t
end_comment

begin_define
define|#
directive|define
name|A
value|1
end_define

begin_comment
comment|// RUN: grep ":18:11: note: instantiated from:" %t
end_comment

begin_define
define|#
directive|define
name|B
value|A
end_define

begin_comment
comment|// RUN: grep ":20:11: note: instantiated from:" %t
end_comment

begin_define
define|#
directive|define
name|C
value|B
end_define

begin_function
name|void
name|bar
parameter_list|()
block|{
comment|// RUN: grep  ":24:3: warning: expression result unused" %t
name|C
expr_stmt|;
block|}
end_function

end_unit

