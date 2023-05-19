#include "pch.h"
#include "CppUnitTest.h"
#include "..\PatternLab6\PatternLab6.cpp"
#include <stdlib.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
    TEST_CLASS(NewYearFactoryTests)
    {
    public:
        TEST_METHOD(NewYearCardCreationTest)
        {

            AbstractFactory* nyFactory = new NYFactory();
            PostCard* nyCard = nyFactory->createPostCard();
            Assert::IsTrue(dynamic_cast<NYCard*>(nyCard) != nullptr); 
            delete nyFactory;
            delete nyCard;
        }

        TEST_METHOD(NewYearCakeCreationTest)
        {
            AbstractFactory* nyFactory = new NYFactory();
            Cake* nyCake = nyFactory->createCake();
            Assert::IsTrue(dynamic_cast<NYCake*>(nyCake) != nullptr);  
            delete nyFactory;
            delete nyCake;
        }
        TEST_METHOD(NewYearPresentCreationTest)
        {
       
            AbstractFactory* nyFactory = new NYFactory();
            Present* nyPresent = nyFactory->createPresent();
            Assert::IsTrue(dynamic_cast<NYPresent*>(nyPresent) != nullptr); 
            delete nyFactory;
            delete nyPresent;
        }

    };

    TEST_CLASS(BirthdaDayDFactoryTests)
    {
    public:
        TEST_METHOD(BirthdayDayPresentCreationTest)
        {
            AbstractFactory* bdFactory = new BDFactory();
            Present* bdPresent = bdFactory->createPresent();
            Assert::IsTrue(dynamic_cast<BDPresent*>(bdPresent) != nullptr); 
            delete bdFactory;
            delete bdPresent;
        }
        TEST_METHOD(BirthdayDayCardCreationTest)
        {
            AbstractFactory* bdFactory = new BDFactory();
            PostCard* bdCard = bdFactory->createPostCard();
            Assert::IsTrue(dynamic_cast<BDCard*>(bdCard) != nullptr);  
            delete bdFactory;
            delete bdCard;
        }

        TEST_METHOD(BirthdayDayCakeCreationTest)
        {
            AbstractFactory* bdFactory = new BDFactory();
            Cake* bdCake = bdFactory->createCake();
            Assert::IsTrue(dynamic_cast<BDCake*>(bdCake) != nullptr); 
            delete bdFactory;
            delete bdCake;
        }
    };
    TEST_CLASS(WomenDayDFactoryTests)
    {
    public:
        TEST_METHOD(WomenDayPresentCreationTest)
        {
   
            AbstractFactory* wdFactory = new WomenDayFactory();
            Present* wdPresent = wdFactory->createPresent();
            Assert::IsTrue(dynamic_cast<WomenDayPresent*>(wdPresent) != nullptr);  
            delete wdFactory;
            delete wdPresent;
        }
        TEST_METHOD(WomenDayCardCreationTest)
        {
            AbstractFactory* wdFactory = new WomenDayFactory();
            PostCard* wdCard = wdFactory->createPostCard();
            Assert::IsTrue(dynamic_cast<WomenDayCard*>(wdCard) != nullptr);  
            delete wdFactory;
            delete wdCard;
        }
    };
}