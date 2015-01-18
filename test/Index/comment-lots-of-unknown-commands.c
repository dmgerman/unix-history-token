begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-load-source-reparse 1 local %s | FileCheck %s
end_comment

begin_comment
comment|// See PR 21254. We had too few bits to encode command IDs so if you created
end_comment

begin_comment
comment|// enough of them the ID codes would wrap around. This test creates commands up
end_comment

begin_comment
comment|// to an ID of 258. Ideally we should check for large numbers, but that would
end_comment

begin_comment
comment|// require a test source file which is megabytes in size. This is the test case
end_comment

begin_comment
comment|// from the PR.
end_comment

begin_comment
comment|/** @s @tr @y @tt @tg @alu @U @I @r @t0 @t1 @ur @S @E @pb @f @pe @lue @re @oa @l @x @R @ute @am @ei @oun @ou @nl @ien @fr @en @tet @le @L @os @A @ro @o @ho @ca @Tie @tl @g @hr @et @fro @ast @ae @nN @pc @tae @ws @ia @N @lc @psg @ta @t2 @D @str @ra @t3 @t @xt @eN @fe @rU @ar @eD @iE @se @st1 @rr @ime @ft @lm @wD @wne @h @otn @use @roi @ldc @ln @d @ee @ep @us @ut @u @n @Nme @min @ma @pct @hd @be @It @id @cm @ua @fs @Al @axn @rt @to @is @fo @i @an @de @tel @nd @dic @Lo @il @tle @axt @ba @ust @ac @tpe @tpl @ctG @ru @m @tG @it @rh @G @rpc @el @er @w @eo @tx @oo @dD @dD */
end_comment

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// CHECK:  CommentAST=[
end_comment

begin_comment
comment|// CHECK:    (CXComment_FullComment
end_comment

begin_comment
comment|// CHECK:       (CXComment_Paragraph
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[s] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tr] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[y] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tt] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tg] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[alu] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[U] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[I] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[r] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[t0] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[t1] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ur] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[S] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[E] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[pb] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[f] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[pe] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[lue] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[re] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[oa] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[l] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[x] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[R] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ute] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[am] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ei] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[oun] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ou] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[nl] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ien] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[fr] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[en] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tet] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[le] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[L] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[os] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[A] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ro] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[o] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ho] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ca] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[Tie] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tl] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[g] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[hr] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[et] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[fro] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ast] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ae] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[nN] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[pc] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tae] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ws] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ia] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[N] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[lc] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[psg] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ta] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[t2] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[D] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[str] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ra] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[t3] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[t] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[xt] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[eN] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[fe] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[rU] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ar] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[eD] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[iE] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[se] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[st1] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[rr] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ime] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ft] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[lm] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[wD] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[wne] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[h] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[otn] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[use] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[roi] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ldc] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ln] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[d] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ee] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ep] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[us] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ut] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[u] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[n] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[Nme] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[min] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ma] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[pct] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[hd] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[be] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[It] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[id] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[cm] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ua] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[fs] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[Al] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[axn] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[rt] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[to] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[is] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[fo] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[i] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[an] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[de] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tel] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[nd] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[dic] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[Lo] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[il] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tle] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[axt] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ba] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ust] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ac] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tpe] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tpl] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ctG] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[ru] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[m] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tG] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[it] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[rh] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[G] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[rpc] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[el] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[er] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[w] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[eo] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[tx] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[oo] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[dD] RenderNormal HasTrailingNewline)
end_comment

begin_comment
comment|// CHECK:         (CXComment_InlineCommand CommandName=[dD] RenderNormal)))]
end_comment

end_unit

