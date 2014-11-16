//////////////////////////////////////////////////////////////////////////
/// @file		floyd_warshall.cpp
/// @brief		FloydWarshallÿ�Զ��������·���㷨
/// @details	COPYRIGHT NOTICE
///			    Copyright (c) 2011
///			    All rights reserved.\n
///
///
/// @author		̷����	chuanqi.tan(at)gmail.com
/// @date		2011/06/17
/// @version	1.0
//////////////////////////////////////////////////////////////////////////
/// �޸ļ�¼��
/// 2011/06/17   17:42	1.0	̷����	����

#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
#include <bitset>
#include <queue>
#include <limits>
#include "graphics.h"

using namespace std;


namespace ita
{
    /// @brief FloydWarshallÿ�Զ��������·���㷨
    ///
    /// Folyd-Warshall��һ����̬�滮�㷨������ʱ��ΪO(V<sup>3</sup>)��������ȨֵΪ���ıߣ����Ǽٶ��˲�����ȨֵΪ���Ļ�·��\n
    /// Folyd-Warshall�ĺ������ڣ�����ڡ����ض�̬�滮�㷨�������Ľ��ˡ�����������ṹ����ʹ��d<sub>ij</sub>(k)����ʾ�Ӷ���i������j��
    /// �����������м䶥������ڼ���{1,2,��,k}��һ�����·����Ȩֵ�������޶�����ʼ��ļ��ɴ��ļ�����ʵ�ֵļ�������\n
    void FloydWarshall()
    {
        cout << "FloydWarshall���·��" << endl;
        //����P384ҳ��ͼ25-1
        vector<int> v;
        v.push_back( 1 );
        v.push_back( 2 );
        v.push_back( 3 );
        v.push_back( 4 );
        v.push_back( 5 );
        GrpahicsViaAdjacencyMatrix<int, int> g( v, Digraph );
        g.Link2Vertex( 0, 1, 3 );
        g.Link2Vertex( 0, 2, 8 );
        g.Link2Vertex( 0, 4, -4 );
        g.Link2Vertex( 1, 4, 7 );
        g.Link2Vertex( 1, 3, 1 );
        g.Link2Vertex( 2, 1, 4 );
        g.Link2Vertex( 3, 2, -5 );
        g.Link2Vertex( 3, 0, 2 );
        g.Link2Vertex( 4, 3, 6 );

        int const n = v.size();	//����ĸ���
        vector<vector<vector<int>>> D( n + 1, vector<vector<int>>( n, vector<int>( n, 0 ) ) );

        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                D[0][i][j] = numeric_limits<int>::max();
                if ( i == j )
                {
                    D[0][i][j] = 0;
                }
                if ( g.GetEdge()[i][j] != 0 )
                {
                    D[0][i][j] = g.GetEdge()[i][j];
                }
            }
        }

        for ( int k = 1; k <= n; ++k )
        {
            //�м�������Ϊ[0 ... k-1]�����
            for ( int i = 0; i < n; ++i )
            {
                for ( int j = 0; j < n; ++j )
                {
                    D[k][i][j] = min( D[k - 1][i][j]
                                      , ( D[k - 1][i][k - 1] == numeric_limits<int>::max() || D[k - 1][k - 1][j] == numeric_limits<int>::max()
                                          ? numeric_limits<int>::max()
                                          : D[k - 1][i][k - 1] + D[k - 1][k - 1][j] ) );
                }
            }
        }

        for ( int i = 0; i < n; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                cout << D[n][i][j] << "  ";
            }
            cout << endl;
        }
    }
}