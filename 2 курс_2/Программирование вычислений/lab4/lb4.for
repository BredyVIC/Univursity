      program main
      
      implicit none
      
      common/data/a,b,seg
      
      real a,b
      real nc6
      real grid
      dimension grid(2**28)
      integer seg
      
      call input
      call make_grid(grid(1))
      
      call trapez(grid,seg+1)
      print*,'---------------'
      
      call nc4(grid,seg+1)
      print*,'---------------'

      print*,nc6(grid,seg+1)
      pause
      
      end
!-------------------------------------------------       
      subroutine input
      
      implicit none
      
      common/data/a,b,seg
      
      real a,b
      integer seg      
      print*,'enter begin and end of the integration interval'
      read*,a,b
      print*,'enter the number of segments'
      read*,seg
      
      end
!-------------------------------------------------       
      subroutine make_grid(grid)
      
      implicit none
      
      common/data/a,b,seg
        
      real a,b
      real h
      real grid
      dimension grid(2**28)
      integer seg
      integer i
      
      h=(b-a)/seg
      do i=0,seg
        grid(i+1)=a+i*h
      end do
      
      end
!------------------------------------------------      
      subroutine trapez(grid,len)
      implicit none
      
      common/data/a,b,seg
      real a,b,h,res,f
      integer len,seg
      real grid
      dimension grid(len)
      integer i
      
      h = grid(2)-grid(1)
      
      res = h*(f(grid(1))+f(grid(len)))/2.0
      do i = 2,len-1
        res = res + h*f(grid(i))
      end do
      
      print*,res
      end
!-------------------------------------------------      
      real function nc6(grid,len)
      
      implicit none
      
      common/data/a,b,seg
        
      real a,b,f,h
      integer seg,len
      real grid
      dimension grid(len)
      real sum_i,sum_j
      integer coefs
      dimension coefs(6)
      integer i,j
      
      h=(grid(2)-grid(1))/5
      
      coefs(1)=19
      coefs(2)=75
      coefs(3)=50
      coefs(4)=50
      coefs(5)=75
      coefs(6)=19
      
      sum_i=0
      sum_j=0
      
      do i=1,seg
        do j=0,5
            sum_j=sum_j+coefs(j+1)*f(grid(i)+j*h)
        end do
        sum_i=sum_i+sum_j
        sum_j=0
      end do
      
      nc6=5*h*sum_i/288
      
      end
!-------------------------------------------------  
      subroutine nc4(grid,len)
      
      implicit none
      
      common/data/a,b,seg
        
      real a,b,f,h,res
      integer seg,len
      real grid
      dimension grid(len)
      real sum_i,sum_j
      integer coefs
      dimension coefs(4)
      integer i,j
      
      h=(grid(2)-grid(1))/3
      
      
      coefs(1)=1
      coefs(2)=3
      coefs(3)=3
      coefs(4)=1
      
      
      sum_i=0
      sum_j=0
      
      do i=1,seg
        do j=0,3
            sum_j=sum_j+coefs(j+1)*f(grid(i)+j*h)
        end do
        sum_i=sum_i+sum_j
        sum_j=0
      end do
      
      res=3*h*sum_i/8
      
      
      print*,res
      
      
      end
!---------------------------------------------------       
      real function f(x)
      
      implicit none
      
      real x
      
      f = 0.25*x**7
      
      end
      
!--------------------------------------------------

