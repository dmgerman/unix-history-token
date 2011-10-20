begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|B
block|{
name|public
operator|:
name|template
operator|<
name|class
name|U
operator|>
name|B
argument_list|(
argument|U p
argument_list|)
block|{  	}
name|template
operator|<
operator|>
name|B
argument_list|(
argument|int p
argument_list|)
block|{
comment|// expected-warning{{explicit specialization of 'B<T>' within class scope is a Microsoft extension}}
block|}
name|template
operator|<
name|class
name|U
operator|>
name|void
name|f
argument_list|(
argument|U p
argument_list|)
block|{
name|T
name|y
operator|=
literal|9
block|; 	}
name|template
operator|<
operator|>
name|void
name|f
argument_list|(
argument|int p
argument_list|)
block|{
comment|// expected-warning{{explicit specialization of 'f' within class scope is a Microsoft extension}}
name|T
name|a
operator|=
literal|3
block|; 	}
name|void
name|f
argument_list|(
argument|int p
argument_list|)
block|{
name|T
name|a
operator|=
literal|3
block|;     }
block|}
expr_stmt|;
end_expr_stmt

end_unit

