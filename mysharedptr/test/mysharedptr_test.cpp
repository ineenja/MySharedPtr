#include <gtest/gtest.h>
#include <iostream>

//static constexpr auto fileName = "TestGenParams1.txt";
//TEST(GenFactoryTests, CreationOfGenerators) {


//    FileReader CheckFile = FileReader(fileName); // копируем данные о сигналах из файлы в программу
//    CheckFile.fillInformation();

//    std::vector<std::shared_ptr<IParameters>> ParamsCheckVector = CheckFile.getSignalsParameters();

//    GeneratorsFactory SignalGenerators = GeneratorsFactory(ParamsCheckVector); // вызываем фабрику генераторов этих сигналов

//    std::vector<std::shared_ptr<const IGenerator>> GensToCheck = SignalGenerators.getSignalsGenerators();

//    EXPECT_TRUE(GensToCheck[0]);
//    EXPECT_TRUE(GensToCheck[1]);
//    EXPECT_EQ(GensToCheck.size(), 2);
//}

//TEST(GenFactoryTests, TypesOfGenerators) {


//    FileReader CheckFile = FileReader(fileName); // копируем данные о сигналах из файлы в программу
//    CheckFile.fillInformation();

//    std::vector<std::shared_ptr<IParameters>> ParamsCheckVector = CheckFile.getSignalsParameters();

//    GeneratorsFactory SignalGenerators = GeneratorsFactory(ParamsCheckVector); // вызываем фабрику генераторов этих сигналов

//    std::vector<std::shared_ptr<const IGenerator>> GensToCheck = SignalGenerators.getSignalsGenerators();

//    ASSERT_TRUE((GensToCheck[0].get()));
//    ASSERT_TRUE((GensToCheck[1].get()));
//}



