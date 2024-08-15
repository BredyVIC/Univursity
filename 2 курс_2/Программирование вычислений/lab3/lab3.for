      program main
      
      implicit none
      
      common/scal/dim,al_size
      common/lim/memlim
      
      real mem
      dimension mem(2**28)
      integer dim,al_size
      integer memlim
      
      memlim = 2**28
      
      call input_scal
      
      call is_mem_enough
      
      call input_di(mem(1))
      call input_al(mem(dim+1))
      call input_ia(mem(dim+al_size+1))
      call input_vect(mem(dim*2+al_size+2))
      
      call func(mem(1),mem(dim+1),mem(dim+al_size+1),
     *mem(dim*2+al_size+2),mem(dim*3+al_size+2))
     
      call output(mem(dim*3+al_size+2))
 
      end
      
      subroutine input_scal
      
      implicit none 
      
      common/scal/dim,al_size
      common/lim/memlim
      
      integer dim,al_size,memlim
      
      open(1, file='scal.txt', status='old')
      read(1,*)dim,al_size
      close(1)
      
      end
      
      subroutine is_mem_enough
      
      implicit none
      
      common/scal/dim,al_size
      common/lim/memlim
      
      integer dim,al_size,memlim
      
      if ((dim*4+1+al_size).gt.memlim) then
        print*,'not enough memory'
        pause
        stop
      end if
      
      end
      
      subroutine input_di(di)
      
      implicit none
      
      common/scal/dim,al_size
      common/lim/memlim
      
      
      integer dim,al_size,memlim
      integer i
      real di
      dimension di(dim)
      
      open(2, file='di.dat',status='old',
     *access='direct',recl=4,form='unformatted')
      do i=1,dim
        read(2,rec=i)di(i)
      end do
      close(2)
      
      end
      
      subroutine input_al(al)
      
      implicit none
      
      common/scal/dim,al_size
      common/lim/memlim
      
      integer dim,al_size,memlim
      integer i
      real al
      dimension al(al_size)
      
      if (al_size.ne.0) then
        open(3, file='al.dat',status='old',
     *access='direct',recl=4,form='unformatted')
        do i=1,al_size
            read(3, rec=i)al(i)
        end do
        close(3)
      end if
      end
      
      subroutine input_ia(ia)
      
      implicit none 
      
      common/scal/dim,al_size
      common/lim/memlim
      
      integer dim,al_size,memlim
      integer i
      real ia
      dimension ia(dim+1)
      
      open(4,file='ia.dat',status='old',
     *access='direct',recl=4,form='unformatted')
      do i=1,dim+1
        read(4,rec=i)ia(i)
      end do
      close(4)
      
      end
      
      subroutine input_vect(vect)
      
      implicit none
      
      common/scal/dim,al_size
      common/lim/memlim
      
      integer dim,al_size,memlim
      integer i
      real vect
      dimension vect(dim)
      
      open(5, file='vect.dat',status='old',
     *access='direct',recl=4,form='unformatted')
      do i=1,dim
        read(5,rec=i)vect(i)
      end do  
      close(5)
   
      end
      
      subroutine output(res)
      
      implicit none
      
      common/scal/dim,al_size
      common/lim/memlim
      
      integer dim,al_size,memlim
      integer i
      
      real res
      dimension res(dim)
      
      
      open(6, file='res.txt', status='old')
      write(6,'(e11.4)')(res(i), i=1,dim)
      close(6)
      
      end

      subroutine func(di,al,ia,vect,res)
      
      implicit none
      
      common/scal/dim,al_size
      common/lim/memlim
      
      integer dim,al_size,memlim
      integer i,j
      real di,al,ia,vect,res
      dimension di(dim),al(al_size),ia(dim+1),
     *vect(dim),res(dim)
      
      do i=1,dim
        res(i)=res(i)+di(i)*vect(i)
        do j = int(ia(i)), int(ia(i+1))-1
            res(i)=res(i)+al(j)*vect(j+i-int(ia(i+1)))
            res(j+i-int(ia(i+1)))=res(j+i-int(ia(i+1)))+al(j)*vect(i)
        end do
      end do
      
      end
      
      
        
            
            
        
        
      
      
      
      
      
      
      
      
      
      
      
      
 
  
      
      
      
