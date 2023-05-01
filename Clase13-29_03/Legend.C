{
auto legend = new TLegend(.1,.7,.3,.9,"Lab. Lesson 1");
legend->AddEntry(graph,"Exp. Points","PE");
legend->AddEntry(f,"Th. Law","L");
legend->Draw();
}