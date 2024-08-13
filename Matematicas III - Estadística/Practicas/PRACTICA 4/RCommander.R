
load("C:/Users/crist/Desktop/Mat 3/PRACTICA 4/Mundo95.RData")
Datos <- within(Datos, {
  ALFA_fac <- as.factor(alfabet)
})
summary(Datos)
library(abind, pos=21)
library(e1071, pos=22)
numSummary(Datos[,"alfabet", drop=FALSE], statistics=c("quantiles", "skewness", 
  "kurtosis"), quantiles=c(0,.25,.5,.75,1,.30), type="1")
numSummary(Datos[,c("alfabet", "espvidaf"), drop=FALSE], statistics=c("quantiles", "cv"), 
  quantiles=c(0,.25,.5,.75,1,.30))
Datos <- within(Datos, {
  urbana_rec <- Recode(urbana, 
  '0:25=[0,25]; 25:50=[25,50]; 50:75=[50,75]; 75:100=[75,100]', as.factor=TRUE)
})
Datos <- within(Datos, {
  urbana_rec <- Recode(urbana, 
  '0:25=[0,25]; 25:50=(25,50]; 50:75=(50,75]; 75:100=(75,100];', as.factor=TRUE)
})
Datos <- within(Datos, {
  urbana_rec <- Recode(urbana, 
  '0:25=[0,25]; 25:50=(25,50]; 50:75=(50,75]; 75:100=(75,100]; ;', as.factor=TRUE)
})
Datos <- within(Datos, {
  urbana_rec <- Recode(urbana, 
  '0:25="[0,25]"; 25:50="(25,50]"; 50:75="(50,75]"; 75:100="(75,100]"; ; ;', as.factor=TRUE)
})
local({
  .Table <- xtabs(~urbana_rec+región, data=Datos)
  cat("\nFrequency table:\n")
  print(.Table)
  cat("\nTotal percentages:\n")
  print(totPercents(.Table))
  .Test <- chisq.test(.Table, correct=FALSE)
  print(.Test)
})
local({
  .Table <- xtabs(~región+urbana_rec, data=Datos)
  cat("\nFrequency table:\n")
  print(.Table)
  cat("\nTotal percentages:\n")
  print(totPercents(.Table))
  .Test <- chisq.test(.Table, correct=FALSE)
  print(.Test)
})
Tapply(calorías ~ región + urbana_rec, mean, na.action=na.omit, data=Datos) 
  # mean by groups
library(colorspace, pos=23)
with(Datos, piechart(religión, xlab="", ylab="", main="religión", col=rainbow_hcl(11), 
  scale="percent"))
local({
  .Table <- with(Datos, table(religión))
  cat("\ncounts:\n")
  print(.Table)
  cat("\npercentages:\n")
  print(round(100*.Table/sum(.Table), 2))
})
with(Datos, Barplot(religión, xlab="religión", ylab="Frequency", label.bars=TRUE))
with(Datos, Hist(urbana, groups=región, scale="percent", breaks="Sturges", col="darkgray"))
with(Datos, Hist(urbana, groups=región, scale="percent", breaks=c(0,25,50,75,100), col="darkgray"))
Datos$Resta <- with(Datos, espvidaf-espvidam)
Boxplot(Resta~región, data=Datos, id=list(method="y"))
library(lattice, pos=24)
xyplot(espvidaf ~ fertilid | región, type="p", pch=16, auto.key=list(border=TRUE), 
  par.settings=simpleTheme(pch=16), scales=list(x=list(relation='same'), 
  y=list(relation='same')), data=Datos)

