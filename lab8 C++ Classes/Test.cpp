#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Matrix.h"
#include <iostream>


void testConstructor1Invalid1() {
		// for constructor1
		int invalid_row1 = -1, invalid_col1 = -2;

		string row1="0 0 0 \n", row2="0 0 0 \n",row3="0 0 0 \n";
			string expected=row1+row2+row3;
    // test constructor1; invalid inputs
		Matrix a = Matrix(invalid_row1,invalid_col1);
			//Matrix a = Matrix();
		ASSERT_EQUAL(expected,a.toString());
	}

void testConstructor1Invalid2() {
		// for constructor1
		int invalid_row2 = 1, invalid_col2 = 0;
		string expected="0 0 0 \n";
		Matrix b = Matrix(invalid_row2,invalid_col2);
		//Matrix b = Matrix();
		ASSERT_EQUAL(expected,b.toString());

	}

void testConstructor1Valid() {
    int valid_row = 3, valid_col = 4;
		// test constructor1; valid inputs
    string row1="0 0 0 0 \n", row2="0 0 0 0 \n",row3="0 0 0 0 \n";
    string expected=row1+row2+row3;
	Matrix d = Matrix(valid_row,valid_col);

        ASSERT_EQUAL(expected,d.toString());

	}

void testConstructor2() {
	  // for constructor2
	    int row=4,col=5;
        int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
        int*input_data[4];
        for (int i=0;i<4;i++){
        	input_data[i]=data[i];
        }
		Matrix f =  Matrix(row,col,input_data);

	    string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	    string expected=row1+row2+row3+row4;
        ASSERT_EQUAL(expected,f.toString());

}
void testConstructor2_add1() {
	  // for constructor2
	    int row=3,col=3;
        int data[3][3] = {{-55,56,55},{107,122,110},{997,889,905}};
        int*input_data[3];
        for (int i=0;i<3;i++){
        	input_data[i]=data[i];
        }
		Matrix f =  Matrix(row,col,input_data);

	    string row1="-55 56 55 \n", row2="107 122 110 \n", row3="997 889 905 \n";
	    string expected=row1+row2+row3;
        ASSERT_EQUAL(expected,f.toString());

}

void testGetElementValid() {
	  // for constructor2
    int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int*input_data[4];
    for (int i=0;i<4;i++){
    	input_data[i]=data[i];
    }
	Matrix f =  Matrix(row,col,input_data);

		int expected= 9;
        ASSERT_EQUAL(expected,f.getElement(1, 3));

	}


void testGetElementInvalid() {
	  // for constructor2
    int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int*input_data[4];
    for (int i=0;i<4;i++){
    	input_data[i]=data[i];
    }
	Matrix f =  Matrix(row,col,input_data);
	string actual ="Empty for Now";
	try {
			int output = f.getElement(10, 2);	// invalid indexes
	}
	catch (std::out_of_range& e){
			 actual = e.what();
	}

    string expected= "Invalid indexes.";
    ASSERT_EQUAL(expected,actual);

}

void testGetElementValid_add3() {
	  // for constructor2
	 int row=1,col=2;
	 int data[1][2] = {{1,2}};
	 int*input_data[1];
	 for (int i=0;i<1;i++){
		 input_data[i]=data[i];
	 }
	 Matrix x =  Matrix(row,col,input_data);

		int expected= 2;
        ASSERT_EQUAL(expected,x.getElement(0, 1));

	}


void testSetElementValid() {
	  int value = 100;
	  int setvalid_row = 0, setvalid_col = 0;
	    int row=4,col=5;
	    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	    int*input_data[4];
	    for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	    }
		Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setvalid_row,setvalid_col);
	  string row1="100 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	  string expected=row1+row2+row3+row4;

      ASSERT_EQUAL(expected,f.toString());
      ASSERT_EQUAL(true,check);

	}



void testSetElementInvalid() {
	  int value = 100;
	  int setinvalid_row = 10, setinvalid_col = 10;
	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	    for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	    }
	  Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setinvalid_row,setinvalid_col);
	  string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	  string expected=row1+row2+row3+row4;
      ASSERT_EQUAL(expected,f.toString());
      ASSERT_EQUAL(false,check);

}

void testSetElementvalid_add2() {
	  int value = 10;
	  int setinvalid_row = 2, setinvalid_col = 1;
	  int row=3,col=2;
      int data[3][2] = {{99,99},{-895,566},{-1000,6}};
	  int*input_data[3];
	    for (int i=0;i<3;i++){
	    	input_data[i]=data[i];
	    }
	  Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setinvalid_row,setinvalid_col);
	  string row1="99 99 \n", row2="-895 566 \n", row3="-1000 10 \n";
	  string expected=row1+row2+row3;
      ASSERT_EQUAL(expected,f.toString());
      ASSERT_EQUAL(true,check);

}


void testCopy() {

	int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int*input_data[4];
	for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	}
	Matrix origin =  Matrix(row,col,input_data);
    Matrix copied = origin.copy(); // make a copy
	string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	string expected=row1+row2+row3+row4;
    ASSERT_EQUAL(expected,copied.toString());
}

void testCopy_add4() {

	int row=1,col=1;
    int data[1][1] = {{113}};
	int*input_data[1];
	for (int i=0;i<1;i++){
	    	input_data[i]=data[i];
	}
	Matrix origin =  Matrix(row,col,input_data);
    Matrix copied = origin.copy(); // make a copy
	string row1="113 \n";
	string expected=row1;
    ASSERT_EQUAL(expected,copied.toString());
}

void testAddToInvalid() {



	   /*Add-to Matrix*/
	    int row_to_add=4; int col_to_add=3;


		int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match

	 	int*add_input_data[4];
	 	for (int i=0;i<4;i++){
	 	    	add_input_data[i]=add_to_data[i];
	 	}

	 	/*Original Matrix*/
	    int row=4;int col=5;
	    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	 	int*input_data[4];
	 	for (int i=0;i<4;i++){
	 	    	input_data[i]=data[i];
	 	}
	 	Matrix origin =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Invalid operation";
        Matrix m = Matrix(row_to_add,col_to_add,add_input_data);


        try{
          m.addTo(origin);

        }
        catch (const std::invalid_argument& e) {
    	   actual = e.what();
        }
        ASSERT_EQUAL(expected,actual);
}


void testAddToValid() {
	   int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match
	   int add_to_above[4][3] = {{1,0,-1}, {2,1,0}, {2,2,2},{0,-1,0}}; // add to 'add_to_data' matrix
	   int row=4;int col=3;

	   int*input_data[4];
	   for (int i=0;i<4;i++){
	 	    	input_data[i]=add_to_data[i];
	   }
	   Matrix m =  Matrix(row,col,input_data);

	   for (int i=0;i<4;i++){
	 	    	input_data[i]=add_to_above[i];
	   }
	   Matrix m1 =  Matrix(row,col,input_data);
	   string row1="4 4 4 \n", row2="3 3 3 \n", row3="2 2 2 \n",row4="1 1 1 \n";
       string expected = row1+row2+row3+row4;



      try{
        m.addTo(m1);
        ASSERT_EQUAL(expected,m.toString());

      }
    catch (const std::invalid_argument& e) {
	   std::cerr << "supposed to be a valid input: " << e.what() << '\n';
    }



}

void testAddToInvalid_add5() {



	   /*Add-to Matrix*/
	    int row_to_add=4; int col_to_add=3;


		int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match

	 	int*add_input_data[4];
	 	for (int i=0;i<4;i++){
	 	    	add_input_data[i]=add_to_data[i];
	 	}

	 	/*Original Matrix*/
	    int row=1;int col=1;
	    int data[1][1] = {{8964}};
	 	int*input_data[1];
	 	for (int i=0;i<1;i++){
	 	    	input_data[i]=data[i];
	 	}
	 	Matrix origin =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Invalid operation";
        Matrix m = Matrix(row_to_add,col_to_add,add_input_data);


        try{
          m.addTo(origin);

        }
        catch (const std::invalid_argument& e) {
    	   actual = e.what();
        }
        ASSERT_EQUAL(expected,actual);
}

void testAddToValid_add6() {
	   int add_to_data[2][2] = {{8,9}, {6,4}}; // add to 'data' matrix, dimension not match
	   int add_to_above[2][2] = {{-8,-9}, {-6,-4}}; // add to 'add_to_data' matrix
	   int row=2;int col=2;

	   int*input_data[2];
	   for (int i=0;i<2;i++){
	 	    	input_data[i]=add_to_data[i];
	   }
	   Matrix m =  Matrix(row,col,input_data);

	   for (int i=0;i<2;i++){
	 	    	input_data[i]=add_to_above[i];
	   }
	   Matrix m1 =  Matrix(row,col,input_data);
	   string row1="0 0 \n", row2="0 0 \n";
       string expected = row1+row2;



      try{
        m.addTo(m1);
        ASSERT_EQUAL(expected,m.toString());

      }
    catch (const std::invalid_argument& e) {
	   std::cerr << "supposed to be a valid input: " << e.what() << '\n';
    }



}





void testSubMatrixValid() {
    int subvalid_row = 3, subvalid_col = 3;


	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string row1="1 2 3 4 \n", row2="6 7 8 9 \n", row3="0 0 1 2 \n",row4="0 0 0 4 \n";
		string expected=row1+row2+row3+row4;

		try{
			Matrix y = f.subMatrix(subvalid_row,subvalid_col);
			ASSERT_EQUAL(expected,y.toString());
		}
		catch (std::out_of_range& e){
			std::cerr << "supposed to be a valid input: " << e.what() << '\n';
		}


}



void testSubMatrixInvalid() {

    int subinvalid_row = 3, subinvalid_col = 6;

	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Submatrix not defined";

		try{
			Matrix y = f.subMatrix(subinvalid_row,subinvalid_col);
		}
		catch (std::out_of_range& e){

			actual = e.what();
		}
		ASSERT_EQUAL(expected,actual);


}

void testSubMatrixValid_add7() {
    int subvalid_row = 0, subvalid_col = 0;


	  int row=4,col=5;
      int data[4][5] = {{-8964,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string expected="-8964 \n";


		try{
			Matrix y = f.subMatrix(subvalid_row,subvalid_col);
			ASSERT_EQUAL(expected,y.toString());
		}
		catch (std::out_of_range& e){
			std::cerr << "supposed to be a valid input: " << e.what() << '\n';
		}


}



void testIsUpperTrTrue() {
		//test isUpperTr()


	  int row=4,col=3;
      int upper1[4][3] = {{1,4,5},{0,9,8},{0,0,7},{0,0,0}};
	  int*input_upper1[4];
	  for (int i=0;i<4;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);



    bool expected = true;
    ASSERT_EQUAL(expected,v.isUpperTr());

}


void testIsUpperTrFalse() {

	int row=3,col=4;
    int upper1[3][4] = {{1,4,1,4},{0,7,6,5},{0,1,4,9}};
	  int*input_upper1[3];
	  for (int i=0;i<3;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);

    bool expected = false;
    ASSERT_EQUAL(expected,v.isUpperTr());

}


void testIsUpperTrFalseNotSquare() {

	int row=3,col=3;
    int upper1[3][3] = {{1,4,1},{1,9,1},{0,2,4}}; // not a square matrix
	int*input_upper1[3];
	for (int i=0;i<3;i++){
	    	input_upper1[i]=upper1[i];
	}
	Matrix v =  Matrix(row,col,input_upper1);

    bool expected = false;
    ASSERT_EQUAL(expected,v.isUpperTr());

}

void testIsUpperTrTrue_add8() {
		//test isUpperTr()


	  int row=4,col=3;
      int upper1[4][3] = {{0,8,9},
    		  	  	  	  {0,0,6},
						  {0,0,0},
						  {0,0,0}};
	  int*input_upper1[4];
	  for (int i=0;i<4;i++){
	    	input_upper1[i]=upper1[i];
	  }
	  Matrix v =  Matrix(row,col,input_upper1);



    bool expected = true;
    ASSERT_EQUAL(expected,v.isUpperTr());

}








bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
    s.push_back(CUTE(testConstructor1Invalid1));

	s.push_back(CUTE(testConstructor1Invalid2));

	s.push_back(CUTE(testConstructor1Valid));

	s.push_back(CUTE(testConstructor2));
	s.push_back(CUTE(testGetElementValid));
	s.push_back(CUTE(testGetElementInvalid));
	s.push_back(CUTE(testSetElementValid));
	s.push_back(CUTE(testSetElementInvalid));
	s.push_back(CUTE(testCopy));
	s.push_back(CUTE(testAddToInvalid));
	s.push_back(CUTE(testAddToValid));
	s.push_back(CUTE(testSubMatrixValid));
	s.push_back(CUTE(testSubMatrixInvalid));
	s.push_back(CUTE(testIsUpperTrTrue));
	s.push_back(CUTE(testIsUpperTrFalse));
	s.push_back(CUTE(testIsUpperTrFalseNotSquare));

	//TODO add your test here
	//self add tests
	s.push_back(CUTE(testConstructor2_add1));
	s.push_back(CUTE(testSetElementvalid_add2));
	s.push_back(CUTE(testGetElementValid_add3));
	s.push_back(CUTE(testCopy_add4));
	s.push_back(CUTE(testAddToInvalid_add5));
	s.push_back(CUTE(testAddToValid_add6));
	s.push_back(CUTE(testSubMatrixValid_add7));
	s.push_back(CUTE(testIsUpperTrTrue_add8));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
