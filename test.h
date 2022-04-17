List l1;

address createElmList(infotype x){
    address temp = new ElmtList();
    temp->info = x;
    temp->next = NULL;

    return temp;
}

int firstElm(List l1){
    return l1.First->info;
}

int lastElm(List l1){
    while(l1.First->next != NULL){
        l1.First = l1.First->next;
    }
    return l1.First->info;
}

void infoList(List l1){
    int overflow = 10;
    for(int i=1;l1.First != NULL; i++){
        cout << "data_" << i << " -> " << l1.First->info << "\n";
        l1.First = l1.First->next;
        if(i >= overflow) break;
    }
}


void testCase(){
    string mycase = "failed";
    int failed = 0;
    {

        address p1 = createElmList(10);

        InsertFirst(&l1, p1);
        if(l1.First){
            if(l1.First->info == 10) mycase = "success\n";

            address p2 = createElmList(11);

            InsertFirst(&l1, p2);

            if(l1.First->next->info != 10) {
                mycase = "failed\n";
                failed++;
            }
        }

    }
    cout << "bonusCase-1 insertfirst: " << mycase;


    {
        address p3 = createElmList(105);
        InsertAfter(&l1, p3, l1.First);
        if(l1.First->info != 11 ||
        l1.First->next->info != 105 ||
        l1.First->next->next->info != 10){
            mycase = "failed\n";
            failed++;
        }
        else {mycase = "success\n";}
    }
    cout << "testcase-2 insertAfter: " << mycase;


    {
        address p3 = createElmList(800);
        InsertLast(&l1, p3);

        if(lastElm(l1) == 800){mycase = "success\n";}
        else {
            mycase = "failed\n";
            failed++;
        }
    }
    cout << "testcase-3 insertLast: " << mycase;

    {
        address p1 = createElmList(900);
        address p2 = createElmList(750);
        InsertFirst(&l1, p1);
        InsertFirst(&l1, p2);

        DelFirst(&l1, &l1.First);

        if(firstElm(l1) == 900) mycase = "success\n";
        else {
            mycase = "failed\n";
            failed++;
        }

    }
    cout << "bonuscase-4 deleteFirst: " << mycase;

    {
        DelAfter(&l1, &l1.First->next, l1.First);

        if(l1.First->next->info == 105) mycase = "success\n";
        else {
            mycase = "failed\n";
            failed++;
        }

    }
    cout << "testscase-5 deleteAfter: " << mycase;


    {
        // insert 2 elm in last l1
        address dElm = createElmList(1011);
        {
            address last = l1.First;
            while(last->next != NULL){
                last = last->next;
            }
            last->next = createElmList(101);
            last->next->next = dElm;

        }
        DelLast(&l1, &dElm);
        // DelAfter(&l1, &l1.First->next, l1.First);

        if(lastElm(l1) == 101) mycase = "success\n";
        else {
            mycase = "failed\n";
            failed++;
        }

    }
    cout << "testcase-6 deleteAfter: " << mycase;

    cout <<"\n\nTotal Failed: " << failed << "\n";
}
