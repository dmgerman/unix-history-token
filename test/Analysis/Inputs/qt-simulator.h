begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_struct
struct|struct
name|QObject
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|QEvent
block|{
enum|enum
name|Type
block|{
name|None
block|}
enum|;
name|QEvent
argument_list|(
argument|Type
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|QCoreApplication
range|:
name|public
name|QObject
block|{
specifier|static
name|void
name|postEvent
argument_list|(
name|QObject
operator|*
name|receiver
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
specifier|static
name|QCoreApplication
operator|*
name|instance
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|QApplication
range|:
name|public
name|QCoreApplication
block|{}
decl_stmt|;
end_decl_stmt

end_unit

