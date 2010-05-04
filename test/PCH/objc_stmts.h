begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* For use with the methods.m test */
end_comment

begin_expr_stmt
unit|@
name|interface
name|A
expr|@
name|end
expr|@
name|interface
name|B
expr|@
name|end
expr|@
name|interface
name|TestPCH
operator|-
operator|(
name|void
operator|)
name|instMethod
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|implementation
name|TestPCH
operator|-
operator|(
name|void
operator|)
name|instMethod
block|{   @
name|try
block|{   }
expr|@
name|catch
argument_list|(
argument|A *a
argument_list|)
block|{   }
expr|@
name|catch
argument_list|(
argument|B *b
argument_list|)
block|{   }
expr|@
name|catch
argument_list|(
argument|...
argument_list|)
block|{   }
expr|@
name|finally
block|{   }
block|}
expr|@
name|end
end_expr_stmt

end_unit

