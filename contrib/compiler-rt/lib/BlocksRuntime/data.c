begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * data.c  *  * Copyright 2008-2010 Apple, Inc. Permission is hereby granted, free of charge,  * to any person obtaining a copy of this software and associated documentation  * files (the "Software"), to deal in the Software without restriction,  * including without limitation the rights to use, copy, modify, merge, publish,  * distribute, sublicense, and/or sell copies of the Software, and to permit  * persons to whom the Software is furnished to do so, subject to the following  * conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/******************** NSBlock support  We allocate space and export a symbol to be used as the Class for the on-stack and malloc'ed copies until ObjC arrives on the scene.  These data areas are set up by Foundation to link in as real classes post facto.  We keep these in a separate file so that we can include the runtime code in test subprojects but not include the data so that compiled code that sees the data in libSystem doesn't get confused by a second copy.  Somehow these don't get unified in a common block. **********************/
end_comment

begin_decl_stmt
name|void
modifier|*
name|_NSConcreteStackBlock
index|[
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_NSConcreteMallocBlock
index|[
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_NSConcreteAutoBlock
index|[
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_NSConcreteFinalizingBlock
index|[
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_NSConcreteGlobalBlock
index|[
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_NSConcreteWeakBlockVariable
index|[
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_Block_copy_error
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

